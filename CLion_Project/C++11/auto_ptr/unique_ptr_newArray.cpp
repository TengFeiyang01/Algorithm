#include <bits/stdc++.h>

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
    static void dis() {
        std::cout << "A::void dis()" << std::endl;
    }
};


int main() {
/*    std::unique_ptr<int[]> up(new int[10]{1, 2, 3, 4});

    for (int i = 0; i < 10; ++i) {
        std::cout << (up[i] = 2) << std::endl;
    }*/

    std::unique_ptr<A[]> upa(new A[5]{});


    return 0;
}
