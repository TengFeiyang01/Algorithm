#include <bits/stdc++.h>

class A {
public:
    A() : data_(new int(0)) {
        std::cout << "A() " << this << std::endl;
    }

    A(const A &other) : data_(new int(*other.data_)) {
        std::cout << "A(const A &other) " << this << " from " << &other << std::endl;
    }

    A(A &&other) {
        std::cout << "A(A &&other) " << this << " from " << &other << std::endl;
        data_ = other.data_;
        other.data_ = nullptr;
    }

    A &operator=(const A &other) {
        std::cout << "A &operator=(const A &other) " << this << " from " << &other << std::endl;
        if (this != &other) {
            delete data_;
            data_ = new int(*other.data_);
        }
        return *this;
    }

    A &operator=(A &&other) {
        std::cout << "A &operator=(A &&other) " << this << " from " << &other << std::endl;
        if (this != &other) {
            delete data_;
            data_ = new int(*other.data_);
            other.data_ = nullptr;
        }
        return *this;
    }

    ~A() {
        if (data_ != nullptr) {
            delete data_;
        }
        std::cout << "~A() " << this << std::endl;
    }

    int *data_;
};

int main() {
    A m;
//    A n(m);
    //std::move(m) 将m变为右值
    A n(std::move(m));  //m：将亡值

    return 0;
}
