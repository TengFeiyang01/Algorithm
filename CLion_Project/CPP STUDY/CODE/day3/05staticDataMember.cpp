#include <bits/stdc++.h>

//static 修饰数据的成员，需要初始化，不可以类内初始化
//类外初始化，需要类名空间且不需要static

//类的声明与实现分开的时候，初始化在 .cpp 中

//大小问题: static声明的数据成员，不占用类对象的大小 存储在data rw 段
//访问 既可以通过对象访问，也可以不通过对象 直接通过类名访问

class A {
public:
    int m_, n_;
    static int cnt;
};

int A::cnt = 0;

int main() {
    A a;
//    std::cout << sizeof(A::cnt) << std::endl;  //4
//    std::cout << sizeof(A) << " " << sizeof(a) << std::endl;
    std::cout << A::cnt << " " << a.cnt << std::endl;

    return 0;
}
