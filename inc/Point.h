#ifndef POINT_H
#define POINT_H

#include <Shape.h>
#include <Color.h>
#include <GL/freeglut.h>

class Point : public Shape  {
    float x;
    float y;
    int size;
    Color color;
    int id;

public:
    Point();
    Point(float _x, float _y, Color color, int _id);
    
    Point(const Point& other);
    

    void draw() const;
    
    float getX() const;
    float getY() const;
    Color getColor() const;
    int getSize() const;
    int getid() const;

    void setX(float _x);
    void setY(float _y);
    void setColor(Color _color);
    void setSize(int _size);
    void grow(float z);
    void shrink(float z);
    bool contains(float _x, float _y) const;

    ~Point();
};

#endif