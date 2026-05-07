#include <GL/gl.h>
#include <Point.h>
#include <iostream>
Point::Point() {
    x = 0.0;
    y = 0.0;
    color = {0, 0, 0};
    size = 15;
    id = 1;
}

Point::Point(float _x, float _y, Color _color, int _id) {
    x = _x;
    y = _y;
    color = _color;
    size = 35;
    id = _id;
}

void Point::draw() const {
    glColor3f(color.r, color.g, color.b);
    glPointSize(size);
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();

    if (isSelected) {
        Point inner = Point(x, y, {0, 0, 0} , id);
        inner.draw();
    }
}




float Point::getX() const {
    return x;
}
float Point::getY() const {
    return y;
}

int Point::getid() const{
    return id;
}
int Point::getSize() const {
    return size;
}
Color Point::getColor() const {
    return color;
}

void Point::setX(float _x) {
    x = _x;
}
void Point::setY(float _y) {
    y = _y;
}
void Point::setSize(int _size) {
    size = _size;
}
void Point::setColor(Color _color) {
    color = _color;
}

void Point::grow(float z){
    
}

void Point::shrink(float z){
    
}

bool Point::contains(float _x, float _y) const {
    if (_x >= x-0.1 && _x <= x +0.1 && _y >= y - 0.1 && _y <= y +0.1) {
        std::cout<<"selected"<< id << std::endl;
        return true;
        
    }
    return false;
}

Point::~Point() {
    //
}