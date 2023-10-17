#include <bits/stdc++.h>

class Complex {
    friend std::istream &operator>>(std::istream &in, Complex &A);

    friend std::ostream &operator<<(std::ostream &out, Complex &A);

public:
    Complex(double r = 0, double i = 0) : real(r), image(i) {}

    void dumpFormat() {
        std::cout << "(" << real << "," << image << ")" << std::endl;
    }

private:
    double real;
    double image;
};

std::istream &operator>>(std::istream &in, Complex &A) {
    in >> A.real >> A.image;
    return in;
}

std::ostream &operator<<(std::ostream &out, Complex &A) {
    out << A.real << " " << A.image << std::endl;
    return out;
}

int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex sum;

//    std::cin >> c1 >> c2;
//    c1.dumpFormat();
//    c2.dumpFormat();
    std::cout << c1 << c2 << std::endl;

    return 0;
}


#if 0
class Mail {
    //声明为友元 是的Sender中的成员函数可以访问Mail的私有成员
    friend class Sender;

public:
    Mail(std::string title, std::string content) : title_(title), contents_(content) {}

private:
    std::string title_;
    std::string contents_;
};

class Sender {
public:
    Sender(std::string addr) : addr_(addr) {}

    Sender &operator<<(const Mail &mail) {
        std::cout << mail.title_ << std::endl;
        std::cout << mail.contents_ << std::endl;
        return *this;
    }

private:
    std::string addr_;
};


int main() {
    Sender sender("2196442691@qq.com");
    Mail mail("Meeting", "关于分红!");
    Mail mail1("通知", "撤销开会");

    sender << mail << mail1;

    return 0;
}
#endif