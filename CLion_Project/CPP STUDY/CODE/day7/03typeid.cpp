#include <bits/stdc++.h>
#include <typeinfo>

class A {
public:
    virtual ~A(){}  //若无此虚函数 称运行时信息不成立
};


class B : public A {

};

class C : public A {

};

int main() {
    B b;
    C c;
//    A* p1 = &b;
//    A* p2 = &c;
//    A* p3 = &b;
    A &r1 = b;
    A &r2 = c;
    A &r3 = b;

    std::cout << typeid(r1).name() << "\n";
    std::cout << typeid(r3).name() << "\n";

    if (typeid(r1) == typeid(r2)) {
        std::cout << "typeid(r1) == typeid(r2)" << "\n";
    }

    if (typeid(r1) == typeid(r3)) {
        std::cout << "typeid(r1) == typeid(r3)" << "\n";
    }

    /*    if (typeid(*p1) == typeid(*p2)) {
        std::cout << "typeid(p1) == typeid(p2)" << "\n";
    }

    if (typeid(*p1) == typeid(*p3)) {
        std::cout << "typeid(p1) == typeid(p3)" << "\n";
    }*/

    return 0;
}
