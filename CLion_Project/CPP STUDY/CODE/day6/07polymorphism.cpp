#include <bits/stdc++.h>

//多态形成的条件
//1 父类中有虚函数 加virtual  声明型关键字 声明有 实现无
//2 子类override覆写了父类的虚函数，子类中同名 同参 同返回
//3 子类对象赋给父类的指针 通过父类的指针调用虚函数 形成多态

class Shape {
public:
    Shape(int x = 0, int y = 0) : x_(x), y_(y) {}

    virtual void draw() {
        std::cout << "draw shape from (" << x_ << ", " << y_ << ")" << std::endl;
    }

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

//    Shape *ps;

/*    while (true) {
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                ps = &c;
                break;
            case 2:
                ps = &r;
                break;
        }
        ps->draw();
    }*/

    return 0;
}
