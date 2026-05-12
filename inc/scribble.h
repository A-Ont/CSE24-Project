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
    float boundx;
    float boundy;

    
    float minx;
    float miny;
    float maxx;
    float maxy;
     
    std::vector<Point*> points; 
    std::vector<float> xVal;
    std::vector<float> yVal;
    
public:
    Scribble();
    Scribble(float _x, float _y, Color _color, float _height, float _width, const std::vector<Point*> points );

    void draw() const;
    bool contains(float _x, float _y) const;
    
    void bounds();


    float getHeight() const;
    float getWidth() const;
    void setX(float _x) override;
    void setY(float _y) override;
    
    void setWidth(float _height);
    void setHeight(float _height);
    void grow(float z);
    void shrink(float);
    
    ~Scribble();
};

#endif