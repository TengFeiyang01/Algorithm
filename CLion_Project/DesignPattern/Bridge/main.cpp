#include <iostream>

class Line {
public:
    virtual void drawLine() = 0;
};

class DotLine : public Line {
public:
    void drawLine() override {
        std::cout << "I can draw DotLine" << std::endl;
    }
};

class SolidLine : public Line {
public:
    void drawLine() override {
        std::cout << "I can draw SolitLine" << std::endl;
    }
};


class Shape {
public:
    Shape(int x, int y, Line *pl = nullptr) :_x(x), _y(y), _pl(pl) {}
    virtual void drawShape() = 0;
protected:
    int _x, _y;
    Line *_pl;
};

class Circle : public Shape {
public:
    Circle(int x, int y, int radius, Line *pl) : Shape(x, y, pl), _radius(radius) {}
    void drawShape() override {
        std::cout << "draw Circle from " << "(" << _x << ", " << _y << ") " << "radius " << _radius << std::endl;
        _pl->drawLine();
    }
protected:
    int _radius;
};

class Rect : public Shape {
public:
    Rect(int x, int y, int l, int w, Line *pl) : Shape(x, y, pl), _l(l), _w(w) {}
    void drawShape() override {
        std::cout << "draw Rect from " << "(" << _x << ", " << _y << ") " << "l " << _l << " w " << _w << std::endl;
        _pl->drawLine();
    }
protected:
    int _l;
    int _w;
};

int main() {
/*
    Circle c(1, 2, 3);
    c.drawShape();
    Rect r(1, 2, 3, 4);
    r.drawShape();
*/
    DotLine dl;
    SolidLine sl;
    Circle c(1, 2, 3, &dl);
    c.drawShape();
    Rect r(1, 2, 3, 4, &sl);
    r.drawShape();


    return 0;
}
