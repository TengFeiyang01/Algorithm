#include <iostream>
class A {
public:
    int add(int a, int b) {
        return a + b;
    }
};

class B : public A {
public:
    //shadow
    int add(int a, int b) {
        return a - b;
    }
};



int main() {

    A a;
    B b;
    std::cout << a.add(2, 3) << std::endl;
    std::cout << b.add(2, 3) << std::endl;

    return 0;
}
