#include "Enums.h"
#include <FL/Enumerations.H>
#include <Toolbar.h>

using namespace bobcat;

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton = new Image(x, y, 25, 25, "./assets/pencil.png");
    eraserButton = new Image(x, y + 25, 25, 25, "./assets/eraser.png");
    mouseButton = new Image(x, y + 50, 25, 25, "./assets/mouse.png");
    circleButton = new Image(x, y + 75, 25, 25, "./assets/circle.png");
    triangleButton = new Image(x, y + 100, 25, 25, "./assets/triangle.png");
    rectangleButton = new Image(x, y + 125, 25, 25, "./assets/rectangle.png");
    HexagonButton = new Image(x, y + 150, 25, 25, "./assets/rectangle.png");
    StarButton = new Image(x, y + 175, 25, 25,"./assets/triangle.png");
    undoButton = new Image(x, y + 200, 25, 25, "./assets/undo.png");
    RedoButton = new Image(x, y + 225, 25, 25, "./assets/clear.png");
    clearButton = new Image(x, y + 250, 25, 25, "./assets/clear.png");

    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    mouseButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    HexagonButton->box(FL_BORDER_BOX);
    StarButton->box(FL_BORDER_BOX);
    undoButton->box(FL_BORDER_BOX);
    RedoButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(mouseButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(HexagonButton, Toolbar::onClick);
    ON_CLICK(StarButton, Toolbar::onClick);
    ON_CLICK(undoButton, Toolbar::onClick);
    ON_CLICK(RedoButton, Toolbar::onClick);
    ON_CLICK(clearButton, Toolbar::onClick);

    selectedTool = PENCIL;
    visualizeSelectedTool();
}

TOOL Toolbar::getSelectedTool() const {
    return selectedTool;
}

ACTION Toolbar::getAction() const {
    return action;
}

void Toolbar::onClick(bobcat::Widget* sender) {
    deselectAllTools();

    action = NONE;
    
    if (sender == pencilButton) {
        selectedTool = PENCIL;
    }
    else if (sender == eraserButton) {
        selectedTool = ERASER;
    }
    else if (sender == mouseButton) {
        selectedTool = MOUSE;
    }
    else if (sender == circleButton) {
        selectedTool = CIRCLE;
    }
    else if (sender == triangleButton) {
        selectedTool = TRIANGLE;
    }
    else if (sender == rectangleButton) {
        selectedTool = RECTANGLE;
    }
    else if (sender == HexagonButton) {
        selectedTool = HEXAGON;
    }
    else if (sender == StarButton) {
        selectedTool = STAR;
    }
    else if (sender == undoButton) {
        action = UNDO;
    }
    else if (sender == RedoButton) {
        action = REDO;
    }
    else if (sender == clearButton) {
        action = CLEAR;
    }

    if (onChangeCb) {
        onChangeCb(this);
    }
    
    visualizeSelectedTool();
    redraw();
}

void Toolbar::visualizeSelectedTool() const {
    if (selectedTool == PENCIL) {
        pencilButton->color(FL_WHITE);
    }
    else if (selectedTool == ERASER) {
        eraserButton->color(FL_WHITE);
    }
    else if (selectedTool == MOUSE) {
        mouseButton->color(FL_WHITE);
    }
    else if (selectedTool == CIRCLE) {
        circleButton->color(FL_WHITE);
    }
    else if (selectedTool == TRIANGLE) {
        triangleButton->color(FL_WHITE);
    }
    else if (selectedTool == RECTANGLE) {
        rectangleButton->color(FL_WHITE);
    }
    else if (selectedTool == HEXAGON) {
        HexagonButton->color(FL_WHITE);
    }
    else if (selectedTool == STAR) {
        StarButton->color(FL_WHITE);
    }
}

void Toolbar::deselectAllTools() const {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    mouseButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    HexagonButton->color(FL_BACKGROUND_COLOR);
    StarButton->color(FL_BACKGROUND_COLOR);
}

Toolbar::~Toolbar() {
    delete pencilButton;
    delete eraserButton;
    delete mouseButton;
    delete circleButton;
    delete triangleButton;
    delete rectangleButton;
    delete HexagonButton;
    delete StarButton;
    delete undoButton;
    delete RedoButton;
    delete clearButton;
}