#include <bits/stdc++.h>

//1 派生类的对象可赋值给基类对象
//2 派生类的对象可初始化基类的引用
//3 派生类的对象的地址可以赋值给指向基类的指针

class Shape {
public:
    Shape(int x = 0, int y = 0) : x_(x), y_(y) {}

    void draw() {
        std::cout << "draw shape from << (" << x_ << ", " << y_ << ")" << std::endl;
    }

protected:
    int x_;
    int y_;
};

class Circle : public Shape {
public:
    Circle(int x = 0, int y = 0, int r = 0) : Shape(x, y), radius_(r) {}

    //shadow
    void draw() {
        std::cout << "draw shape from << (" << x_ << ", " << y_ << ")" << " radius" << radius_ << std::endl;
    }

protected:
    int radius_;
};

class Rect : virtual public Shape {

};

int main() {
    Shape s(1, 2);

    s.draw();

    Circle c(4, 5, 6);
    c.draw();

//    派生类赋值给基类
//    s = c;
//    s.draw();

//  派生类的对象可初始化基类的引用
//    Shape &rs = c;
//    rs.draw();  //(4, 5)

//3 派生类的对象的地址可以赋值给指向基类的指针
//    Shape *ps = &c;
//    ps->draw();  //(4, 5)

    return 0;
}
