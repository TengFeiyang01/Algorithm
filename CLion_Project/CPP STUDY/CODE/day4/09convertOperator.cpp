#include <bits/stdc++.h>

//转换构造函数的本质 也是构造函数

//explicit 用于修饰构造函数

//自定义类型操作符函数转换
//class 源类{
//    operator 目标类(void)
//    {
//        return 目标类构造器(源类实参);
//    }
//}
//eg：
//operator int() {
//    std::cout << "operator int() {}" << std::endl;
//    return this->x_;
//}

class Point3D {
    friend class Point2D;
public:
    explicit Point3D(int x = 0, int y = 0, int z = 0) : x_(x), y_(y), z_(z) {}

    void dumpFormat() {
        std::cout << x_ << " " << y_ << " " << z_ << std::endl;
    }

private:
    int x_;
    int y_;
    int z_;
};

class Point2D {
    friend class Point3D;
public:
    Point2D(int x = 0, int y = 0) : x_(x), y_(y) {}

    //无参无返回 还可以return
    operator Point3D() {
        return Point3D(this->x_, this->y_, rand() % 100);
    }

//    Point2D operator+(int x) {
//        return Point2D(this->x_ + x, this->y_);
//    }

    //实现Point2d + int 返回 int
    operator int() {
        std::cout << "operator int() {}" << std::endl;
        return this->x_;
    }

    void dumpFormat() {
        std::cout << x_ << " " << y_ << std::endl;
    }

private:
    int x_;
    int y_;
};

Point3D convert(Point2D &d2) {
    return Point3D(d2);
}

int main() {
    Point2D d2(1, 2);
//    std::cout << d2 + 3 << "\n";
//    (d2 + 1).dumpFormat();

    srand(time(NULL));

//    Point3D d3 = d2;
    auto d3 = convert(d2);
    d3.dumpFormat();

    return 0;
}
