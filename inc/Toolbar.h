#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <bobcat_ui/all.h>
#include <Enums.h>
#include <bobcat_ui/image.h>

class Toolbar : public bobcat::Group {
    bobcat::Image* pencilButton;
    bobcat::Image* eraserButton;
    bobcat::Image* mouseButton;
    bobcat::Image* circleButton;
    bobcat::Image* triangleButton;
    bobcat::Image* rectangleButton;
    bobcat::Image* undoButton;
    bobcat::Image* RedoButton;
    bobcat::Image* clearButton;
    bobcat::Image* HexagonButton;
    bobcat::Image* StarButton;
    bobcat::Image* enlargeButton;
    bobcat::Image*reduceButton;
    
    TOOL selectedTool;
    ACTION action;
    
    void onClick(bobcat::Widget* sender);
    void visualizeSelectedTool() const;
    void deselectAllTools() const;

public:
    Toolbar(int x, int y, int w, int h);

    TOOL getSelectedTool() const;
    ACTION getAction() const;

    ~Toolbar();
};

#endif