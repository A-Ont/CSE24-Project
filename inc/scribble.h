#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include <Shape.h>
#include<Point.h>
#include <GL/freeglut.h>
#include <cmath>
#include <vector>

class Scribble : public Shape {
    float height;
    float width;
    
    std::vector<Point*> points; 
    
public:
    Scribble();
    Scribble(float _x, float _y, Color _color, float _height, float _width, const std::vector<Point*> points );

    void draw() const;
    bool contains(float _x, float _y) const;


    float getHeight() const;
    float getWidth() const;
    void setWidth(float _height);
    void setHeight(float _height);
    void grow(float z);
    void shrink(float);
    
    ~Scribble();
};

#endif