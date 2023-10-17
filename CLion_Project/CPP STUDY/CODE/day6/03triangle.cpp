#include <bits/stdc++.h>

//提取各父类中相同的成员，构成祖父类
//让各父类继承祖父类
//虚继承是一种继承的扩展 virtual
//虚继承也是一种设计的结果

class A {
public:
    int data_;
};

class X : virtual public A {
public:
    X(int d) {
        std::cout <<"X()" << std::endl;
        data_ = d;
    }

    void setData(int d) {
        data_ = d;
    }
};

class Y  : virtual public A {
public:
    Y(int d) {
        std::cout << "Y()" << std::endl;
        data_ = d;
    }

    int getData() {
        return data_;
    }
};

class Z : public X, public Y {
public:
    Z(int i, int j) :X(i), Y(j) {}
    void dis() {
//        std::cout << X::data_ << std::endl;
//        std::cout << Y::data_ << std::endl;
        std::cout << data_ << std::endl;
    }
};

int main() {
    Z z(1, 2);
//    z.dis();
    z.setData(100);
    std::cout << z.getData() << std::endl;
    z.dis();


    return 0;
}
