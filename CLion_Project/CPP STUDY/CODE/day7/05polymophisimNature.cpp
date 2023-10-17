#include <bits/stdc++.h>

class Base {
public:
    virtual void f() { std::cout << "Base::f" << std::endl; }

    virtual void g() { std::cout << "Base::g" << std::endl; }

    virtual void h() { std::cout << "Base::h" << std::endl; }

    int a;
};

class Derive : public Base {
public:
    virtual void f() { std::cout << "Derive::f" << std::endl; }

    virtual void g1() { std::cout << "Derive::g" << std::endl; }

    virtual void h2() { std::cout << "Derive::h" << std::endl; }
};

typedef void (*FUNC)();

int main() {
    std::cout << "Base size:" << sizeof(Base) << std::endl;

    //子类的虚函数表中有子类和父类
    Derive b;
    std::cout << "对象的起始地址：" << &b << std::endl;

    std::cout << "虚函数表的地址：" << (size_t **) *(size_t *) &b << std::endl;
    std::cout << "虚函数表第一个函数的起始地址：" << *((size_t **) *(size_t *) &b) << std::endl;
    std::cout << "虚函数表第二个函数的起始地址：" << *((size_t **) *(size_t *) &b + 1) << std::endl;

    FUNC pf0 = (FUNC)*(((size_t **) *(size_t *) &b));
    FUNC pf1 = (FUNC)*(((size_t **) *(size_t *) &b + 1));
    FUNC pf2 = (FUNC)*(((size_t **) *(size_t *) &b + 2));
    FUNC pf3 = (FUNC)*(((size_t **) *(size_t *) &b + 3));
    FUNC pf4 = (FUNC)*(((size_t **) *(size_t *) &b + 4));
//    FUNC pf5 = (FUNC)*(((size_t **) *(size_t *) &b + 5));

    //若实现多态 则先多态 后父类虚函数 后子类虚函数
    pf0();
    pf1();
    pf2();
    pf3();
    pf4();
//    pf5();


    return 0;
}
