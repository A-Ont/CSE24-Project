
#include <Hexagon.h>


Hexagon::Hexagon() {
    x = 0.0;
    y = 0.0;
    radius = 0.2;
    color = {0, 0, 0};
}

Hexagon::Hexagon(float _x, float _y, float _radius, Color _color) {
    x = _x;
    y = _y;
    radius = _radius;
    color = _color;
}

void Hexagon::draw() const {
    glColor3f(color.r, color.g, color.b);

    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / 6;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
        }
    glEnd();
    if (isSelected) {
        Hexagon inner = Hexagon(x, y, radius - 0.05,{1, 1, 1});
        inner.draw();
    }
}

bool Hexagon::contains(float _x, float _y) const {
    if (_x >= x - radius/2 && _x <= x + radius/2 && _y >= y - radius/2 && _y <= y + radius/2) {
        return true;
    }
    return false;
}


float Hexagon::getRadius() const {
    return radius;
}
void Hexagon::setRadius(float _radius) {
    radius = _radius;
}

Hexagon::~Hexagon() {
    //
}