#include "Point.h"
#include <GL/gl.h>
#include <scribble.h>

#include <iostream>
#include <vector>

Scribble::Scribble() {

    std::cout << "we're calling default constructor" << std::endl;
    width = 0.2;
    height = 0.2;
    color = {0, 0, 0};
    boundx = 0;
    boundy = 0;

    points.push_back(new Point());
    x = points[0]->getX();
    y = points[0]->getY();
}

Scribble::Scribble(float _x, float _y, Color _color, float _height,
                   float _width, const std::vector<Point *> pointh) {
    std::cout << "we're calling overloaded constructor" << std::endl;
    // _x, _y = mouse coords
    printf("_x = %f, _y = %f\n", _x, _y);

    width = _width;
    height = _height;
    color = _color;

    for (size_t i = 0; i < pointh.size(); i++) {
        points.push_back(new Point(*pointh[i]));
        // pointh[i]->draw();
        // std::cout << "drawing pointh" << std::endl;
    }

    x = _x - points[0]->getX();
    y = _y - points[0]->getY();

    minx = points[0]->getX();
    maxx = points[0]->getX();
    miny = points[0]->getY();
    maxy = points[0]->getY();

    for (size_t i = 0; i < points.size(); i++) {
        if (minx > points[i]->getX()) {
            minx = points[i]->getX();
        }
        if (maxx < points[i]->getX()) {
            maxx = points[i]->getX();
        }
        if (miny > points[i]->getY()) {
            miny = points[i]->getY();
        }
        if (maxy < points[i]->getY()) {
            maxy = points[i]->getY();
        }
    }

    boundx = maxx - minx;
    boundy = maxy - miny;

    for (size_t i = 0; i < points.size(); i++) {

        //    xVal.push_back(points[i]->getX() - x);
        //   yVal.push_back(points[i]->getY() - y );
        xVal.push_back(points[i]->getX());
        yVal.push_back(points[i]->getY());
    }
}

void Scribble::draw() const {
    glColor3f(color.r, color.g, color.b);
    glPointSize(15);
    for (size_t i = 0; i < xVal.size(); i++) {
        //    float gg = xVal[i] + x;
        //    float ff = yVal[i] + y;

        float gg = xVal[i] - x;
        float ff = yVal[i] - y;
        glBegin(GL_POINTS);
        // glVertex2f( x - gg, y + ff);
        glVertex2f(gg + x, ff + y);
    }
    glEnd();
    // std::cout<<x<<y<<std::endl;
    // printf("x = %f | y = %f | minx = %f | miny = %f | maxx = %f | maxy =
    // %f\n", x, y,minx,miny,maxx,maxy);
    if (isSelected) {
        // std::cout << "we've selected the scribble" << std::endl;
        glColor3f(0, 0, 0);
        glLineWidth(5);
        glBegin(GL_LINE_LOOP);
        glVertex2f(minx -.1, miny -.1);
        glVertex2f(maxx + .1, miny-.1);
        glVertex2f(maxx + .1, maxy + .1);
        glVertex2f(minx -.1, maxy +.1);
        glEnd();

        // if (isSelected) {
        //     Rectangle inner = Rectangle(x, y, width - 0.05, height - 0.05,
        //     {1, 1, 1});
        // inner.draw();
    }
}

bool Scribble::contains(float _x, float _y) const {
    // _x, _y = mouse coords
    if (_x >= minx -.05 && _x <= maxx +.05 && _y >= miny -.05 && _y <= maxy +.05) {
        return true;
    }
    return false;
}
void Scribble::setX(float _x) {

    std::vector<float> tempx;
    for (size_t i = 0; i < xVal.size(); i++) {
        if (xVal[i] >= xVal[0]) {
            tempx.push_back(xVal[i] - xVal[0]);
        }
        if (xVal[i] < xVal[0]) {
            tempx.push_back(xVal[i] - xVal[0]);
        }
    }

    for (size_t i = 0; i < xVal.size(); i++) {
        xVal[i] = tempx[i] + _x;
    }
    minx = xVal[0];
    maxx = xVal[0];
    for (size_t i = 0; i < xVal.size(); i++) {
        if (minx > xVal[i]) {
            minx = xVal[i];
        }
        if (maxx < xVal[i]) {
            maxx = xVal[i];
        }
        
    }

}

void Scribble::setY(float _y) {

    std::vector<float> tempy;
    for (size_t i = 0; i < yVal.size(); i++) {
        if (yVal[i] >= yVal[0]) {
            tempy.push_back(yVal[i] - yVal[0]);
        }
        if (yVal[i] < yVal[0]) {
            tempy.push_back(yVal[i] - yVal[0]);
        }
    }

    for (size_t i = 0; i < yVal.size(); i++) {
        yVal[i] = tempy[i] + _y;
    }
    miny = yVal[0];
    maxy = yVal[0];
    for (size_t i = 0; i < yVal.size(); i++) {
        if (miny > yVal[i]) {
            miny = yVal[i];
        }
        if (maxy < yVal[i]) {
            maxy = yVal[i];
        }
        
    }
}
float Scribble::getWidth() const { return width; }
float Scribble::getHeight() const { return height; }
void Scribble::setWidth(float _width) { width = _width; }
void Scribble::setHeight(float _height) { height = _height; }
void Scribble::grow(float z) { return; }
void Scribble::shrink(float z) { return; }

Scribble::~Scribble() {
    //
}

// in progress