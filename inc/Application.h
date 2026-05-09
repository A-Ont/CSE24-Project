#ifndef APPLICATION_H
#define APPLICATION_H

#include <bobcat_ui/all.h>
#include <Canvas.h>
#include <ColorSelector.h>
#include <Toolbar.h>
#include <Color.h>
#include <bobcat_ui/bobcat_ui.h>

class Application : public bobcat::Application_ {
    bobcat::Window* window;
    Canvas* canvas;
    Toolbar* toolbar;
    ColorSelector* colorSelector;

    int lineid;

    void onCanvasMouseDown(bobcat::Widget* sender, float x, float y);
    void onCanvasMouseDrag(bobcat::Widget* sender, float x, float y);
    void onCanvasMouseUp(bobcat::Widget* sender, float x, float y);
    void onToolbarChange(bobcat::Widget* sender);
    void onColorChange(bobcat::Widget* sender);

public:
    Application();

    ~Application();
};

#endif

