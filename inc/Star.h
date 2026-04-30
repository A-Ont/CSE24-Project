#ifndef Star_H
#define Star_H

#include <Shape.h>
#include <Color.h>
#include <GL/freeglut.h>

class Star : public Shape {
    float base;
    float height;
    
public:
    Star();
    Star(float _x, float _y, float _base, float _height, Color _color);

    void draw() const;
    bool contains(float _x, float _y) const;


    float getBase() const;
    float getHeight() const;

    void setBase(float _base);
    void setHeight(float _height);

    ~Star();
};

#endif