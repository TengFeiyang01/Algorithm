#include <bits/stdc++.h>

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
};


void foo() {
//    A a;
//    A *p = new A;
//    delete p;
    //memory
    //智能指针 自动执行析构
    std::shared_ptr<A> p(new A);
}

int main() {

    foo();

    return 0;
}
