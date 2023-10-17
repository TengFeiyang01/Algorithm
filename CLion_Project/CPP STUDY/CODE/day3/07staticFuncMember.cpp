#include <bits/stdc++.h>

//类内外，声明和定义，类内声明需要加static 类外无需加static

//静态成员函数, 只能访问静态的成员。不能访问非静态的成员的原因是 因为静态函数里面没有this指针

//非静态函数，可以访问静态成员

class A {
public:
    static void manageA();
    static void manageB(){}

    void foo() {
        std::cout << a << std::endl;
        manageA();
        manageB();
    }
private:
    static int a;
    int x_;
};

int A::a = 100;

void A::manageA() {
    std::cout << a << std::endl;
//    std::cout << x_ << std::endl;
//    foo();
    manageB();
}

int main() {
    A a;
    a.foo();
    a.manageA();
    a.manageB();

    A::manageA();
    A::manageB();

    return 0;
}
