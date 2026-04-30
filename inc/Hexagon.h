#ifndef HEXAGON_H
#define HEXAGON_H
#include <Shape.h>
#include <GL/freeglut.h>
#include <cmath>

class Hexagon : public Shape {
    float radius;
    
public:
    Hexagon();
    Hexagon(float _x, float _y, float _radius, Color _color);

    void draw() const;
    bool contains(float _x, float _y) const;


    float getRadius() const;
    void setRadius(float _radius);

    ~Hexagon();
};

#endif
