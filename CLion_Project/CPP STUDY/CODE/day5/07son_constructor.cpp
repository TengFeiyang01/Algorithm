#include <bits/stdc++.h>

//子类的构造过程中  1 空体无参 2 重载 3 默认
//调用父类的构造器 标配会被调用，没有标配则必须显示调用
//或隐 必须有标配 或显

//调用内嵌构造器 标配会被调用，没有标配则必须显示调用
//或隐 必须有标配  或显

class C {
public:
    C(int c = 0) :c_(c) {
        std::cout << "C()" << std::endl;
    }
    int c_;
};

class A {
public:
    A(int a = 0) :a_(a) {
        std::cout << "A()" << std::endl;
    }
    int a_ ;
};

class B : public A {
public:
    B(int a, int b) :A(a), b_(b) {
        std::cout << "B()" << std::endl;
    }
    int b_;
    C c;  //嵌套子对象
};


int main() {
    B b(3, 5);  //A() B()

    std::cout << b.a_ << " " << b.b_ << " " << b.c.c_ << std::endl;
    return 0;
}
