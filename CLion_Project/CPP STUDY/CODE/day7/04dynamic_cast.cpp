#include <bits/stdc++.h>

class A {
public:
    virtual ~A(){}  //若无此虚函数 称运行时信息不成立
};


class B : public A {

};

class C : public A {

};


int main() {
    A *p = new B;
    B *pb;
    pb = dynamic_cast<B*> (p);
    if (pb != nullptr) {
        std::cout << "pb-> new B" << "\n";
    }
    C *pc;
    //下转会判断类型
    pc = dynamic_cast<C*> (p);
    if (pc != nullptr) {
        std::cout << "pc-> new C" << "\n";
    } else {
        std::cout << "pc!-> new C" << "\n";
    }

    return 0;
}
