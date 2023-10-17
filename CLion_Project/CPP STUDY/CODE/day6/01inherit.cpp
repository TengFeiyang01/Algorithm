#include <bits/stdc++.h>

//shadow 在父类中 出现了重名标识符（函数成员，数据成员），就会构成shadow
//如果想访问被shadow成员 需要加上父类的命名空间

class Base {
public:
    int pub = 1;
protected:
    int pro = 2;
private:
    int pri;
};

class Derive : protected Base {
public:
    void foo() {
        std::cout << pub << std::endl;
        std::cout << pro << std::endl;
    }
    int a;
protected:
    int b;
private:
    int c;
};

class M : public Derive {
public:
    void foo() {
        std::cout << pub << std::endl;
        std::cout << pro << std::endl;
//        foo();
        Derive::foo();
    }
};

int main() {
    Derive d;
//    d.pub;
//    d.pro;
//    d.foo();
    M m;
    m.foo();

    return 0;
}
