#include <bits/stdc++.h>

//转换构造函数的本质 也是构造函数

//explicit 用于修饰构造函数

class Point2D {
    friend class Point3D;
public:
    Point2D(int x = 0, int y = 0) : x_(x), y_(y) {}

private:
    int x_;
    int y_;
};

class Point3D {
public:
    explicit Point3D(int x = 0, int y = 0, int z = 0) : x_(x), y_(y), z_(z) {}

    explicit Point3D(const Point2D &d2) {
        this->x_ = d2.x_;
        this->y_ = d2.y_;
        srand(time(nullptr));
        this->z_ = rand() % 100;
    }

    void dumpFormat() {
        std::cout << x_ << " " << y_ << " " << z_ << std::endl;
    }

private:
    int x_;
    int y_;
    int z_;
};

Point3D convert(Point2D d2) {
    return Point3D(d2);
}

int main() {
    Point2D d2(10, 100);
//    Point3D d3(d2);

    //加了explicit之后 需要显示的转换
//    Point3D d3 = static_cast<Point3D>(d2);
//    Point3D d3 = convert(d2);
    Point3D d3;
    d3.dumpFormat();

    Point3D *p = new Point3D;
    p->dumpFormat();

    return 0;
}
