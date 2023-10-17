#include <bits/stdc++.h>

//虚基类：被虚继承的类叫虚基类
//虚继承：是一种继承的扩展

class A {
//public:
//    A(int i) {}
protected:
    int data_;
};

class B : virtual public A {
public:
    B(int i = 0) {
        std::cout << "B" << "\n";
        data_ = i;
    }
};

class C : virtual public A {
public:
    C(int i = 0) {
        std::cout << "C" << "\n";
        data_ = i;
    }
};

class D : public B, public C {
public:
    D(int d) {
        std::cout << "D(int i)" << std::endl;
        data_ = d;
    }

    void dis() {
        std::cout << data_ << std::endl;
    }
};

int main() {
    D d(10);
    d.dis();

    return 0;
}
