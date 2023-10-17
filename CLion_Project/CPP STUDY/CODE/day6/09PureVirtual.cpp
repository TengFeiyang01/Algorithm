#include <bits/stdc++.h>

//纯虚函数 virtual 没有实现体 被“初始化”为0
//纯接口类 才配具体 拥有纯虚函数 含纯虚函数的类成为抽象基类
//抽象基类不能实例化 不能产生对象 若派生类仍未实现 派生类仍为抽象基类

//析构函数 virtual destructor

class Shape {
public:
    Shape(int x = 0, int y = 0) : x_(x), y_(y) {}

    //纯虚函数
    virtual void draw() = 0;

protected:
    int x_;
    int y_;
};

class Circle : public Shape {
public:
    Circle(int x = 0, int y = 0, int r = 0) : Shape(x, y), radius_(r) {}

    virtual void draw() {
        std::cout << "draw Circle from (" << x_ << ", " << y_ << ")" << " radius" << radius_ << std::endl;
    }

protected:
    int radius_;
};

class Rect : virtual public Shape {
public:
    Rect(int x = 0, int y = 0, int w = 0, int l = 0) : Shape(x, y), width_(w), length_(l) {}

    virtual void draw() {
        std::cout << "draw Rect from (" << x_ << ", " << y_ << ")" << " Width" << width_
                  << " length" << length_ << std::endl;
    }

protected:
    int width_;
    int length_;
};

int main() {
    Circle c(3, 4, 5);

    Shape *ps = &c;
    //调用的父类的draw()
    ps->draw();

    Rect r(7, 8, 9, 10);
    ps = &r;
    ps->draw();


    return 0;
}
