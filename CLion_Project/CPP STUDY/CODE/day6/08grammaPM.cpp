#include <bits/stdc++.h>

//virtual 声明型关键字 用于声明一个函数是虚  子类覆写的函数也是virtual
//覆写 同名 同参 同返回 override
//虚函数在子类中的访问属性并不影响多态。具体需求要看子类

class A {
public:
    virtual void func() {
        std::cout << "A::func" << std::endl;
    }
};

class B : public A {
public:
    void func() override {
        std::cout << "B:func" << std::endl;
    }
};

int main() {
    B b;
    A *pa = &b;

    pa->func();

    return 0;
}
