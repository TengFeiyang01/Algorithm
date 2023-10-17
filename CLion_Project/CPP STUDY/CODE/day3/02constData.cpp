#include <bits/stdc++.h>
//const 修饰，对象、类数据成员 必须初始化
//const 初始化，一种情况在类内，另一种在 initial list
//initial list 一方面，效率的问题，为了一些新拓展的功能 提供 解决场所或是办法

//const 修饰的数据成员，可以在非const函数中使用，但是不可更改

class A {
public:
    A(int i): i_(i) {}

    void dis() {
        std::cout << i_ << std::endl;
    }
private:
    const int i_;
};

int main() {
    A a(10);
    a.dis();

    return 0;
}

#if 0
class A {
public:
    //初始化列表的时候是唯一能够修改 const所修饰的成员变量的时机
    //initial list
    A(int &zz) :x(200), y(200), z(zz) {
        std::cout << "const int x = " << x << std::endl;
        std::cout << z << std::endl;
    }

    void dis() {
        std::cout << z << std::endl;
    }

private:
    //const 修饰，对象、类数据成员 必须初始化
    //const int x = 100;
    const int x = 100;
    int y;
    //引用必须初始化
    int &z;
};

int main() {
    int z = 10;
    A a(z);

    a.dis();

    return 0;
}
#endif