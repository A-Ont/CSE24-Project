// #include <scribble.h>

// Scribble::Scribble() {
//     x = 0.0;
//     y = 0.0;
    
//     width = 0.2;
//     height = 0.2;
//     color = {0, 0, 0};
// }

// Scribble::Scribble(float _x, float _y, float _width, float _height, Color _color) {
//     x = _x;
//     y = _y;
//     width = _width;
//     height = _height;
//     color = _color;
// }

// void Scribble::draw() const {
//     glColor3f(color.r, color.g, color.b);

//     glBegin(GL_POLYGON);
//         glVertex2f(x - width/2, y + height/2);
//         glVertex2f(x + width/2, y + height/2);
//         glVertex2f(x + width/2, y - height/2);
//         glVertex2f(x - width/2, y - height/2);
//     glEnd();
//     // if (isSelected) {
//     //     Rectangle inner = Rectangle(x, y, width - 0.05, height - 0.05, {1, 1, 1});
//     // inner.draw();
//     }





// bool Scribble::contains(float _x, float _y) const {
//     if (_x >= x - width/2 && _x <= x + width/2 && _y >= y - height/2 && _y <= y + height/2) {
//         return true;
//     }
//     return false;
// }

// float Scribble::getWidth() const {
//     return width;
// }
// float Scribble::getHeight() const {
//     return height;
// }
// void Scribble::setWidth(float _width) {
//     width = _width;
// }
// void Scribble::setHeight(float _height) {
//     height = _height;
// }


// Scribble::~Scribble() {
//     //
// }