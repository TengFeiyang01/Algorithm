#include <bits/stdc++.h>

//一个对象所占用的空间大小只取决于该对象中数据成员所占用的空间，而与成员函数无关
//类的成员函数仅有一份，在对象调用过程中，传入对象的地址，具体表现为 this 指针

class Time {
public:
    Time(int h, int m, int s) :hour_(h), min_(m), sec_(s) {}
    void dis() {
        std::cout << hour_ << ":" << min_ << ":" << sec_ << std::endl;
    }
private:
    int hour_, min_, sec_;
};

int main() {
    std::cout << sizeof(Time) << std::endl;  //12

    Time(12, 02, 30).dis();
    Time(12, 02, 31).dis();
    Time(12, 02, 32).dis();

    return 0;
}
