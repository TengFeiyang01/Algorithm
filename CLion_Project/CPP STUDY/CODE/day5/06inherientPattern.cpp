#include <bits/stdc++.h>

//protected 在外部访问的时候，等价于private
//在public继承中可见
//派生类全盘接收父类的成员 除了构造器与析构器

//继承方式不影响派生类成员的访问 影响了父类的成员，在子类内部和对象访问权限

class A {
public:
    int pub;
protected:
    int pro;
private:
    int pri;
};

class B : public A {
public:
    int pubb;

    void func() {
//        std::cout << pubb << " " << prob << " " << prib << std::endl;
        std::cout << pub << std::endl;
        std::cout << pro << std::endl;
//        std::cout << pri << std::endl;  //public 不可见基类私有
    }

protected:
    int prob;
private:
    int prib;
};

class C : public B{
public:
    void foo() {
        std::cout << pro << std::endl;
    }
};

int main() {
    B b;
    b.pubb;
    b.func();

    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(B) << std::endl;

    return 0;
}
