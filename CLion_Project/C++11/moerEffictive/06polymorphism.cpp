#include <bits/stdc++.h>

class Oper {
public:
    virtual int op(int x, int y) = 0;
};

class Add : public Oper {
public:
    int op(int x, int y) override {
        return x + y;
    }
};

class Minus : public Oper {
public:
    int op(int x, int y) override {
        return x - y;
    }
};

int main() {
    Add add;
    Minus minus;
    std::cout << add.op(1, 2) << " " << minus.op(2, 1) << std::endl;

    return 0;
}
