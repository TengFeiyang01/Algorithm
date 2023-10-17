#include <bits/stdc++.h>

class A {
public:
//    A() {}
    void dis() {
        std::cout << i << std::endl;
    }
//private:
    //只能在这里初始化 static
    static const int i = 100; //data ro 段
};

int main() {
    A a;

    std::cout << A::i << std::endl;

    return 0;
}
