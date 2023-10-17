#include <bits/stdc++.h>

//RAII 资源获取即初始化  防止内存泄漏
class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
    static void dis() {
        std::cout << "A::void dis()" << std::endl;
    }
};

int main() {
//    std::unique_ptr<A> ap(new A);
//    ap->dis();
//    (*ap).dis();
//    ap->dis();

    //auto_ptr 已经被废弃 可能导致多次析构
/*    int *p = new int(10);
    {
        std::auto_ptr<int> ap(p);
        std::cout << *ap << std::endl;
    }
    std::auto_ptr<int>ap2(p);*/



    return 0;
}
