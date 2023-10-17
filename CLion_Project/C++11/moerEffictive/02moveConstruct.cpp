#include <bits/stdc++.h>

//本质特定意义（使用场景下的浅拷贝） 取名为移动构造 解决效率问题
//对象当中含有堆上的资源-->深拷贝

class A {
public:
    A() : data_(new int(0)) {
        std::cout << "A() " << this << std::endl;
    }

    A(const A &other) :data_(new int(*other.data_)) {
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

A getTemp() {
    return A();
}

void func(A a) {

}

int main() {
/*    A a;
    A b(a);

    std::cout << a.data_ << " " << b.data_ << "\n";*/

//    移动语义 解决临时对象
//    A &&ret = getTemp();

/*    A a;  //此时a会消失
    func(a);*/

//    A a;
//    A b(a);  //调用深拷贝构造A(const A &other)
    A c;
    A d;
    d = std::move(c);  //调用移动赋值

    return 0;
}
