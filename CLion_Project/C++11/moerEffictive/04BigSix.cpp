#include <bits/stdc++.h>

class A {
public:
    explicit A(int *i = nullptr) : i_(i) { //initializer_list
        i_ = new int;
        std::cout << "A(int *i = nullptr)" << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
        if (i_ != nullptr) {
            delete i_;
        }
    }

    A(const A &other) {
        std::cout << "A(const A &other)" << std::endl;
        i_ = new int;
        *i_ = *other.i_;
    }

    A &operator=(const A &other) {
        std::cout << "A &operator=(const A &other)" << std::endl;
        if (this != &other) {
            delete i_;
            i_ = new int;
            *i_ = *other.i_;
        }
        return *this;
    }

    A(A &&other)  noexcept {  //移动构造
        std::cout << "A(A &&other)" << std::endl;
        i_ = other.i_;
        other.i_ = nullptr;
    }

    A &operator=(A &&other)  noexcept {
        std::cout << "A &operator=(A &&other)" << std::endl;
        if (this != &other) {
            i_ = other.i_;
            other.i_ = nullptr;
        }
        return *this;
    }

private:
    int *i_;
};

int main() {
    A a;  //默认构造
    A b(a);  //拷贝构造
    A c(std::move(a));  //移动构造
    A d;
    d = std::move(c);  //移动赋值
    A e = b;  //拷贝赋值
    std::move(e);

    return 0;
}
