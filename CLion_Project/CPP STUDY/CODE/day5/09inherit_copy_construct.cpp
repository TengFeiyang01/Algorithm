#include <bits/stdc++.h>

//当子类中不自实现时，默认调用父类的拷贝构造
//若自实现 不做特殊处理 此时只会调用父类的默认构造器 此时失去了拷贝构造的意义
//特殊处理 显示调用父类的拷贝构造函数
//子类对象赋值给父类的引用 赋值兼容

//当内嵌子对象 子类不自实现时，默认调用内嵌子对象的拷贝构造
//若自实现，不做特殊处理，此时只会调用父类的构造上  此时失去了拷贝构造的意义
//特殊处理 显示调用内嵌子对象的拷贝构造函数

class C {
public:
    C() {
        std::cout << "C()" << std::endl;
    }
    C(const C &other) {
        std::cout << "C(const C &other)" << std::endl;
    }
};

class A {
public:
    A(int x = 99) {
        std::cout << "A()" << std::endl;
        a = x;
    }

    A(const A &other) {
        this->a = other.a;
        std::cout << "A(const A &other)" << std::endl;
    }

    int a;
};

class B : public A {
public:
    B(int x, int y) : A(x), c() {
        std::cout << "B()" << std::endl;
        b = y;
    }

/*    B(const B &other) :A(other) {
        this->b = other.b;
        std::cout << "B(const B &other)" << std::endl;
    }*/

    B(const B &other) :A(other), c(other.c){
        this->b = other.b;
        std::cout << "B(const B &other)" << std::endl;
    }
private:
    int b;
    C c;
};

int main() {
    B b(199, 200);  //199 200
    B b1(b);
//    std::cout << b1.a << " " << b1.b;   //199 200

    return 0;
}
