#include <bits/stdc++.h>

class Stu {
public:
    Stu(std::string name = "") :name_(name) {}
    void dis() {
        std::cout << name_ << std::endl;
    }
private:
    std::string name_;
};

int main() {
//    Stu s("a");
    //对象数组
//    Stu sa[100] = {Stu("x"), Stu("y")};

//    Stu *ps = new Stu("abc");
    Stu *ps = new Stu[10];  //    Stu(std::string name = "") :name_(name) {} 建议实现带默认参数的构造函数

    return 0;
}
