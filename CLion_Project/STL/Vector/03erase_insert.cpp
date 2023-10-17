#include <bits/stdc++.h>

class A {
public:
    A() {
        std::cout << "无参构造 " << this << std::endl;
    }

    A(int i) : data_(i) {
        std::cout << "含参构造 " << this << std::endl;
    }

    A(const A &other) {
        std::cout << "拷贝构造 " << this << " from " << &other << std::endl;
    }

    A &operator=(const A &other) {
        std::cout << "拷贝赋值 " << this << " from " << &other << std::endl;
    }

    ~A() {
        std::cout << "析构函数 " << this << std::endl;
    }

    void dis() {
        std::cout << data_ << "\n";
    }

private:
    int data_ = 0;
};

int main() {
    std::vector<A> va;
    va.reserve(10);
    A a;
    va.push_back(a);
    va.push_back(a);
    va.push_back(a);

//    va.insert(va.begin(), a);
    va.erase(va.begin());

    return 0;
}
