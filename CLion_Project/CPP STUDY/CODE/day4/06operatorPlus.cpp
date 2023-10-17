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

    Complex &operator+=(const Complex &other) {
//        std::cout << this << " " << &other << "\n";
        this->real += other.real;
        this->image += other.image;
        return *this;
    }

    Complex operator-(const Complex &other) {
        Complex ans;
        ans.real = this->real - other.real;
        ans.image = this->image - other.image;
        return ans;
    }

    const Complex operator-() const {
        return Complex(-this->real, -this->image);
    }

    Complex &operator-=(const Complex &other) {
        this->real -= other.real;
        this->image -= other.image;
        return *this;
    }

    Complex& operator++() {
        this->real++;
        this->image++;
        return *this;
    }

    void dumpFormat() const {
        std::cout << "(" << real << "," << image << ")" << std::endl;
    }

    //哑元
    const Complex operator++(int) {
        Complex r(*this);
        this->real++;
        this->image++;
        return r;
    }

private:
    double real;
    double image;
};

int main() {
    Complex c1(1, 0), c2(2, 0), c3(3, 0);
    Complex sum;
    sum = c1 + c2;

    c1 += c2 += c3;
//
//    c1.dumpFormat();
//    c2.dumpFormat();
//    c3.dumpFormat();

    //返回值是const时无法通过编译
//    Complex cc = -c1;
//    -cc = Complex(1, 0);
//
//    cc.dumpFormat();
    //const对象不能调用非const成员函数 因此需要const
//    (-(-c1)).dumpFormat();

    //若返回值为 Complex& 下列两个表达式相同
    //否则不同

//    ((c1.operator++()).operator++()).dumpFormat();
//    (++++c1).dumpFormat();
//    c1.dumpFormat();
    int a = 10;
    auto y = a++;

//    auto x = c1++;
//    c1.dumpFormat();
//    x.dumpFormat();
//    (c1++++).dumpFormat();

    return 0;
}
