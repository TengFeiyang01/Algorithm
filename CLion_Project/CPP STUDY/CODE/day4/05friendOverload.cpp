#include <bits/stdc++.h>

//同类之间无私处，异类之间无友元
//声明为谁的友元 就可以通过谁的对象访问其私有成员

class Complex {
public:
    Complex(double r = 0, double i = 0) : real(r), image(i) {}

    Complex operator+(const Complex &other) {
        Complex ans;
        ans.real = this->real + other.real;
        ans.image = this->image + other.image;
        return ans;
    }

    Complex operator+=(const Complex &other) {
//        std::cout << this << " " << &other << "\n";
        this->real += other.real;
        this->image += other.image;
        return *this;
    }

    void dumpFormat() {
        std::cout << "(" << real << "," << image << ")" << std::endl;
    }

private:
    double real;
    double image;
};

int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex sum;
    sum = c1 + c2;
    sum.dumpFormat();
    c1 += c1;
    c1.dumpFormat();

    return 0;
}

#if 0
//友元重载 即全局函数重载

class Complex {
    friend Complex operator+(Complex &c1, Complex &c2);
public:
    Complex(double r = 0, double i = 0): real(r), image(i) {}

    void dumpFormat() {
        std::cout << "(" << real << "," << image << ")" << std::endl;
    }
private:
    double real;
    double image;
};

Complex operator+(Complex &c1, Complex &c2) {
    Complex ans;
    ans.real = c1.real + c2.real;
    ans.image = c1.image + c2.image;
    return ans;
}

int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex sum;
    sum = c1 + c2;
    sum.dumpFormat();

    return 0;
}
#endif
