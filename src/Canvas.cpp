#include "Color.h"
#include "Hexagon.h"
#include "Point.h"
#include "Shape.h"
#include <Canvas.h>
#include <algorithm>

Canvas::Canvas(int x, int y, int w, int h) : bobcat::Canvas_(x, y, w, h) {
    //
}

void Canvas::addPoint(float x, float y, Color color, int id) {
    shapes.push_back(new Point(x, y, color, id));
}

void Canvas::addCircle(float x, float y, float radius, Color color) {
    shapes.push_back(new Circle(x, y, radius, color));
}

void Canvas::addTriangle(float x, float y, float base, float height, Color color) {
    shapes.push_back(new Triangle(x, y, base, height, color));
}

void Canvas::addRectangle(float x, float y, float width, float height, Color color) {
    shapes.push_back(new Rectangle(x, y, width, height, color));
}

void Canvas::addHexagon(float x, float y, float radius, float height, Color color) {
    shapes.push_back(new Hexagon(x, y, radius, color));
}

void Canvas::addStar(float x, float y, float width, float height, Color color) {
    shapes.push_back(new Star(x, y, width, height, color));
}

void Canvas::change_color(Shape* selected_shape,Color color)
{
    selected_shape->setColor(color);
}

Shape* Canvas::getSelectedShape(){
    return selectedShape;
}

void Canvas::tryToSelectShape(float x, float y, Color color) {
    if (selectedShape) {
        selectedShape->deselect();
        for (int i = 0; i < shapes.size(); i++){
            shapes[i]->deselect();
        }
        selectedShape = nullptr;
    }
    
    
    for (size_t i = 0; i < shapes.size(); i++) {
        if (shapes[i]->contains(x, y)) {
            selectedShape = shapes[i];
            selectedShape->select();
            if(selectedShape->getid() != 0){
                // std::cout<<selectedShape->getid()<<std::endl;
                for (int i = 0; i < shapes.size(); i++){
                    if(shapes[i]->getid() == selectedShape->getid()){
                        shapes[i]->select();
                    }
                }
            }
            break;
        }
    }
}

void Canvas::tryToMoveSelectedShape(float x, float y) {
    for (size_t i = 0; i < shapes.size(); i++) {
        if (shapes[i]->getIsSelected()) {
            shapes[i]->setX(x);
            shapes[i]->setY(y);
        }
    }
}

void Canvas::growShape(){
    if (selectedShape) {
        selectedShape->grow(0.1);
    }
}

void Canvas::shrinkShape(){
    if (selectedShape) {
        selectedShape->shrink(0.1);
    }
}

void Canvas::clear() {
    for (size_t i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
    
    
}

void Canvas::Undo(){
    if (shapes.size() >= 0){    
    Shape* XVar = shapes[shapes.size() - 1];
    
    variables.push_back(XVar);
       
    //std::cout<<"size: " << variables.size()<<std::endl;
   //delete shapes[shapes.size()-1];
   shapes.pop_back(); 
}
}

void Canvas::Redo(){
    if (variables.size() >= 0){
    Shape* newx = variables[variables.size() - 1];
    variables.pop_back();
    shapes.push_back(newx);
          //variables[variables.size() - 1]->draw();
       }
      
    
}

void Canvas::render() {
    for (size_t i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }

    for (size_t i = 0; i < points.size(); i++) {
        points[i]->draw();
    }
}

void Canvas::reColor(Color color){
    
    
    
    Shape* currentShape = getSelectedShape();
    if(currentShape){
        change_color(currentShape, color);
    }
}

Canvas::~Canvas() {
    clear();
}