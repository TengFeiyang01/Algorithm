#include <bits/stdc++.h>

//友元类中的所有成员函数都可以访问私有成员
//已知三点求面积  海伦公式 s := sqrt(p*(p-a)(p-b)(p-c)) p:=(a+b+c)/2

class Point {
    friend class ManagePoint;

public:
    Point(double x = 0, double y = 0) : x_(x), y_(y) {}

    void dumpFormat() {
        std::cout << "(" << x_ << "," << y_ << ")" << std::endl;
    }

private:
    double x_;
    double y_;
};

class ManagePoint {
public:
    double getDistance(const Point &p1, const Point &p2) {
        double dx = p1.x_ - p2.x_;
        double dy = p1.y_ - p2.y_;
        return std::sqrt(dx * dx + dy * dy);
    }

    double getArea(const Point &p1, const Point &p2, const Point &p3) {
        double a = getDistance(p1, p2), b = getDistance(p2, p3), c = getDistance(p1, p3);
        double p = (a + b + c) / 2;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main() {
    Point p1(1, 4), p2(4, 1), p3(1, 1);
    p1.dumpFormat();
    p2.dumpFormat();

    ManagePoint mp;

    std::cout << mp.getDistance(p1, p2) << std::endl;
    std::cout << mp.getArea(p1, p2, p3) << std::endl;

//    std::cout << getDistance(p1, p2);

    return 0;
}
