#include <bits/stdc++.h>

class A {
public:
    void print(int x, int y) {
        std::cout << x << " " << y << "\n";
    }
};

int main() {
    A a;
    auto f = [a] () mutable { a.print(1, 2); };
    f();

    auto f1 = [](auto && PH1, auto && PH2, auto && PH3) { PH1->print(std::forward<decltype(PH2)>(PH2), std::forward<decltype(PH3)>(PH3)); };

    f1(a, 3, 5);

    return 0;
}
