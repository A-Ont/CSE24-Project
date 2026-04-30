#include <Shape.h>

Shape::Shape() {
    x = 0.0;
    y = 0.0;
    color = {0, 0, 0};
}

float Shape::getX() const {
    return x;
}
float Shape::getY() const {
    return y;
}
Color Shape::getColor() const {
    return color;
}

void Shape::setX(float _x) {
    x = _x;
}
void Shape::setY(float _y) {
    y = _y;
}
void Shape::setColor(Color _color) {
    color = _color;
}
void Shape::select() {
    isSelected = true;
}
void Shape::deselect() {
    isSelected = false;
}

Shape::~Shape() {
    //
}