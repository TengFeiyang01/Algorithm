#include <bits/stdc++.h>

//传参与返回
class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }

    A(const A& other) {
        std::cout << "A(const A& other)" << std::endl;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

void foo(A a) {

}

int main() {
    A a;
//    A b = a;

    foo(a);  //传参时存在拷贝构造

    return 0;
}
