#include <bits/stdc++.h>

//const 修饰函数后，承诺不改变，在本函数内不会发生改变数据成员的行为。
//声明之后 实现体之前

//只能调用const的成员函数

//由const构成的重载函数，非const对象，优先调用非const版本，再没有非const版本的时候，也可以调用const版本
//若对象为const对象，只能调用const版本的成员函数  大部分库提供两个版本

//inline const static 声明 和 定义

class A {
public:
    A(int x, int y) :x_(x), y_(y) {}

    void func() {
        std::cout << "void func()" << std::endl;
        std::cout << x_ << " " << y_ << std::endl;
//        x_ = 200;
    }

    void func() const {
        std::cout << "void func() const" << std::endl;
        std::cout << x_ << " " << y_ << std::endl;
    }

private:
    int x_;
    int y_;
};


int main() {
    const A a(3, 4);
    a.func();

    return 0;
}

#if 0
//const 修饰，类函数成员，不可以修饰全局函数
//const 构成的重载问题
int add(int &a, int &b) {
    return  a + b;
}

int add(const int &a, const int &b) {
    return a + b;
}

class A {
public:
    void func() const {

    }

    void func() {

    }
};

int main() {
    int a = 5, b = 3;
    std::cout << add(a, b) << std::endl;

    //add(const int &a, const int &b)
    std::cout << add(3, 5) << std::endl;

    return 0;
}
#endif