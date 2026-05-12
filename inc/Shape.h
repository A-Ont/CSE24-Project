#ifndef SHAPE_H
#define SHAPE_H

#include <Color.h>

class Shape {
protected:
    float x;
    float y;
    Color color;
    bool isSelected;
    float z;
    int id;
    
    
public:
    Shape();

    float getX() const;
    float getY() const;
   //virtual int getid() const = 0;
    Color getColor() const;
    bool getIsSelected() const;


    virtual void draw() const = 0;
    virtual void grow(float z) = 0;
    virtual void shrink(float z) = 0;
    virtual bool contains(float _x, float _y) const = 0;


    virtual void setX(float _x);
    virtual void setY(float _y);
    void setColor(Color _color);
    void select();
    void deselect();


    virtual ~Shape();
};

#endif