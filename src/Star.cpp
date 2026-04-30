#include <GL/gl.h>
#include <Star.h>

Star::Star() {
    x = 0.0;
    y = 0.0;
    base = 0.2;
    height = 0.2;
    color = {0, 0, 0};
}

Star::Star(float _x, float _y, float _base, float _height, Color _color) {
    x = _x;
    y = _y;
    base = _base;
    height = _height;
    color = _color;
}

void Star::draw() const {
    glColor3f(color.r, color.g, color.b);

    glBegin(GL_POLYGON);
        glVertex2f(x - base/2, y - height/2);
        glVertex2f(x, y + height/2);
        glVertex2f(x + base/2, y - height/2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x - base/2, y + height/4);
    glVertex2f(x + base/2, y + height/4);
    glVertex2f( x, y - ((3 * height)/4));
    glEnd();
    if (isSelected) {
        Star inner = Star(x, y, base - 0.05, height - 0.05, {1, 1, 1});
    inner.draw();
    }
}

bool Star::contains(float _x, float _y) const {
    if (_x >= x - base/2 && _x <= x + base/2 && _y >= y - height/2 && _y <= y + height/2) {
        return true;
    }
    return false;
}


float Star::getBase() const {
    return base;
}
float Star::getHeight() const {
    return height;
}
void Star::setBase(float _base) {
    base = _base;
}
void Star::setHeight(float _height) {
    height = _height;
}

Star::~Star() {
    //
}