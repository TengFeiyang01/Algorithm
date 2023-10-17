#include <bits/stdc++.h>

//前向声明问题 前向声明 是一种不完全类型的声明，不能定义对象。
//但是可以定义指针和引用 做参数和返回值，仅用在函数声明中

class Point;

class ManagePoint {
public:
    double getDistance(const Point &p1, const Point &p2);
};

class Point {
    //friend放在哪里都可以 一般放在类的入口出
    friend double ManagePoint::getDistance(const Point &p1, const Point &p2);
public:
    Point(double x = 0, double y = 0) :x_(x), y_(y) {}
    void dumpFormat() {
        std::cout << "(" << x_ << "," << y_ << ")" << std::endl;
    }
private:
    double x_;
    double y_;
};

double ManagePoint::getDistance(const Point &p1, const Point &p2) {
    double dx = p1.x_ - p2.x_;
    double dy = p1.y_ - p2.y_;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    Point p1(3, 4), p2(7, 8);
    p1.dumpFormat();
    p2.dumpFormat();

    ManagePoint mp;

    std::cout << mp.getDistance(p1, p2) << std::endl;

//    std::cout << getDistance(p1, p2);

    return 0;
}
