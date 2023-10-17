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
    std::list<A> la;
    //使用emplace时 仅调用一次构造 即原位构造
//    la.emplace(la.begin(), 200);

    //再la末尾使用参数200构造一个A对象
    la.emplace_back(209);
//    la.push_back(A());
//    la.push_back(A());
/*    A a(100);

    std::cout << "================\n";
    la.emplace_back(a);*/

    return 0;
}
