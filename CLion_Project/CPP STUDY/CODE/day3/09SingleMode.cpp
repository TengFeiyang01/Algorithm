#include <bits/stdc++.h>

//实现共享用的 单例模式
//见 new 见 delete  见new 不见 delete  不见new 见delete  不见new 不见 delete

class Single {
public:
    static Single *getInstance() {
        if (ins_ == nullptr) {
            ins_ = new Single;
        }
        return ins_;
    }

    static void releceInstance() {
        if (ins_ != nullptr) {
            delete ins_;
            ins_ = nullptr;
        }
    }

private:
    Single(); //此时不能通过常规手段生成对象
    Single(const Single &);
    Single &operator=(const Single &);
    static Single * ins_;
};

Single * Single::ins_ = nullptr;

Single::Single() {

}

int main() {
    Single *ps = Single::getInstance();
    Single *ps1 = Single::getInstance();
    Single *ps2 = Single::getInstance();

//    std::cout << ps << " " << ps1 << " " << ps2 << std::endl;

    Single::releceInstance();

    return 0;
}
