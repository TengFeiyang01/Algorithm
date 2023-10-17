#include <bits/stdc++.h>

//const 修饰的对象，期内可以有非const数据成员，但是只能调用const修饰的成员函数
//针对const又可能修饰对象，往往提供两个版本，构成重载

class A {
public:
    A(int x, int y) :x_(x), y_(y) {}

    void dis() {
        std::cout << x_ << " " << y_ << std::endl;
    }

    void dis() const {
        std::cout << x_ << " " << y_ << std::endl;
    }

private:
    int x_;
    const int y_;
};

int main() {
    const A a(3, 4);
    a.dis();

    return 0;
}
