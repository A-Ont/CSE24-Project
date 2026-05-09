 #include <scribble.h>

 Scribble::Scribble() {
    x = 0.0;
    y = 0.0;
    
    width = 0.2;
    height = 0.2;
    color = {0, 0, 0};
    points.push_back(new Point());
 }

Scribble::Scribble(float _x, float _y,  Color _color, float _height, float _width, const std::vector<Point*> pointh) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    color = _color; 
    for (size_t i = 0; i < pointh.size(); i++){
    
        points.push_back(new Point(*pointh[i]));
    }
      
      
        
}
 

void Scribble::draw() const {
    glColor3f(color.r, color.g, color.b);

    for (size_t i = 0; i < points.size(); i++){
       glPointSize(15);
    glBegin(GL_POINTS);
        glVertex2f(points[i]->getX(),points[i]->getY() ); 
    }
    glEnd();
    // if (isSelected) {
    //     Rectangle inner = Rectangle(x, y, width - 0.05, height - 0.05, {1, 1, 1});
    // inner.draw();
    }


     

bool Scribble::contains(float _x, float _y) const {
    float minx = points[0]->getX();
    float maxx = points[0]->getX();
    float miny = points[0]->getY();
    float maxy = points[0]->getY();
    float boundx = 0;
    float boundy = 0;
   
     
     for (size_t i = 0; i < points.size(); i++){
        if (minx > points[i]->getX()) {
             minx = points[i]->getX();
        }
        if (maxx < points[i]->getX()) {
           maxx = points[i]->getX();
        }
        if (miny > points[i]->getY()) {
             minx = points[i]->getY();
        }
        if (maxy < points[i]->getY()) {
           maxy = points[i]->getY();
        }
     }

      boundx = maxx - minx;
      boundy = maxy - miny;
    if (_x >= x - boundx/2 && _x <= x + boundx/2 && _y >= y - boundy/2 && _y <= y + boundy/2) {
        return true;
    }
    return false;
}

float Scribble::getWidth() const {
    return width;
}
float Scribble::getHeight() const {
    return height;
}
void Scribble::setWidth(float _width) {
    width = _width;
}
void Scribble::setHeight(float _height) {
    height = _height;
}
void Scribble::grow(float z){
    return;
}
void Scribble::shrink(float z){
    return;
}


Scribble::~Scribble() {
    //
}

//in progress