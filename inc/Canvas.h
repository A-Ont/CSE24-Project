#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/canvas.h>
#include <Point.h>
#include <Circle.h>
#include <Triangle.h>
#include <Rectangle.h>
#include <Hexagon.h>
#include <Star.h>
#include <Shape.h>
#include <vector>


class Canvas : public bobcat::Canvas_ {
    
    std::vector<Shape*> shapes;
    std::vector<Point*> points;
    std::vector<Shape*> variables;
    Shape* selectedShape;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, Color color);
    void addCircle(float x, float y, float radius, Color color);
    void addTriangle(float x, float y, float base, float height, Color color);
    void addRectangle(float x, float y, float width, float height, Color color);
    void addHexagon(float x, float y, float width, float height, Color color);
    void addStar(float x, float y, float base, float height, Color color);
    void tryToSelectShape(float x, float y);
    void tryToMoveSelectedShape(float x, float y);
    void Undo();
    void Redo();
    void clear();

    void render();

    ~Canvas();
};

#endif