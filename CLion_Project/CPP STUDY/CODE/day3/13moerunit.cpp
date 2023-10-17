#include <bits/stdc++.h>

struct Point {
    int add(int x, int y) {
        return x + y;
    }
    int minus(int x, int y) {
        return x - y;
    }
    int mul(int x, int y) {
        return x * y;
    }
    int div(int x, int y) {
        return x / y;
    }
};

//统一接口
int oper(Point &p, int (Point::*pf)(int x, int y), int x, int y) {
    return (p.*pf)(x, y);
}

typedef int(Point::*PF)(int x, int y);

int main() {
    Point p;
    auto pf = &Point::add;
//    PF pf = &Point::add;

    std::cout << oper(p, pf, 1, 2) << std::endl;

    return 0;
}
