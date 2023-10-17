#include <bits/stdc++.h>

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }

    void xxx() {
        std::cout << "xxx" << std::endl;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

//自实现智能指针类
template<class T>
class SmartPtr {
public:
    SmartPtr(T *p) : p_(p) {};

    ~SmartPtr() {
        delete p_;
    }

    T* operator->() {
        return p_;
    }

    T* operator*() {
        return p_;
    }

    T& getTref() {
        return* p_;
    }

private:
    T *p_;
};

void foo() {
    SmartPtr<A> p(new A);
//    p.getTref().xxx(); //operator. -> operator*
//    p.get()->xxx();  /operator->
    (*p)->xxx();
//    p->xxx();
}

int main() {
    foo();

    return 0;
}
