#include <bits/stdc++.h>

class A {
public:
    A() {
        std::cout << this << " Constructor!" << std::endl;
    }

    A(const A &other) {
        std::cout << this << " cpoy from" << &other << std::endl;
    }

    ~A() {
        std::cout << this << " Destructor!" << std::endl;
    }

    A& operator=(const A &other) {
        std::cout << this << " operator =" << &other << std::endl;
        return *this;
    }
};

A &foo() {
    A a;
    return a;
}

int main() {
    A a = foo();
    getchar();

    return 0;
}


#if 0

//RVO/NRVO (不)具名返回值优化
A func() {
    //匿名对象 一次构造 一次析构
//    return A();
    A a;
    return a;
}

int main() {

    A x;
    x = func();
//    A x = func();
    getchar();
    return 0;
}
#endif

#if 0
void func(A &a) {

}

int main() {
    A a;

    //加引用可以不用拷贝
    func(a);

    return 0;
}
#endif

#if 0
//中间变量
//栈上的对象，是可以返回的，不可以返回栈上对象的引用
int func() {
    int a = 3;
    return a;
}

int main() {
    int i = 4;
    i = func();

    return 0;
}
#endif