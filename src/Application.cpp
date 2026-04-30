#include <Enums.h>
#include <Application.h>

using namespace bobcat;

Application::Application() {
    window = new Window(25, 75, 400, 400, "Project");

    canvas = new Canvas(50, 0, 350, 350);

    toolbar = new Toolbar(0, 0, 50, 400);

    colorSelector = new ColorSelector(50, 350, 350, 50);

    window->add(canvas);
    window->add(toolbar);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasMouseDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);

    window->show();
}

void Application::onCanvasMouseDown(bobcat::Widget* sender, float x, float y) {
    Color color = colorSelector->getSelectedColor();
    TOOL tool = toolbar->getSelectedTool();
    
    if (tool == PENCIL) {
        canvas->addPoint(x, y, color); 
    }
    else if (tool == ERASER) {
        canvas->addPoint(x, y, {1, 1, 1}); 
    }
    else if (tool == CIRCLE) {
        canvas->addCircle(x, y, 0.1, color);
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(x, y, 0.2, 0.2, color);
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(x, y, 0.2, 0.2, color);
    }
    else if (tool == HEXAGON) {
        canvas->addHexagon(x, y, 0.2, 0.2, color);
    }
    else if (tool == STAR) {
        canvas->addStar(x, y, 0.2, 0.2, color);
    }
    else if (tool == MOUSE) {
        canvas->tryToSelectShape(x, y);
    }
    
    canvas->redraw();
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR){
        canvas->clear();
        canvas->redraw();
    }
    else if (action == UNDO){
        canvas->Undo();
        canvas->redraw();
    }
    else if (action == REDO){
        canvas->Redo();
        canvas->redraw();
    }
}

void Application::onCanvasMouseDrag(bobcat::Widget* sender, float x, float y) {
    Color color = colorSelector->getSelectedColor();
    TOOL tool = toolbar->getSelectedTool();
    
    if (tool == PENCIL) {
        canvas->addPoint(x, y, color); 
    }
    else if (tool == ERASER) {
        canvas->addPoint(x, y, {1, 1, 1}); 

    }
    else if (tool == MOUSE) {
        canvas->tryToMoveSelectedShape(x, y);
    }
    
    canvas->redraw();
}

Application::~Application() {
    delete canvas;
    delete toolbar;
    delete colorSelector;
    delete window;
}