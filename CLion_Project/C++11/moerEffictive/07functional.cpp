#include <bits/stdc++.h>

//function同一接口，可包装 函数、函数指针、lambda、仿函数

int add(int x, int y) {
    return x + y;
}

int minus(int x, int y) {
    return x - y;
}

class Divide {
public:
    int operator()(int x, int y) {
        return x / y;
    }
};

typedef int(*MINUS)(int x, int y);

int main() {
    //函数
    auto op = std::function<int(int, int)>(add);
    std::cout << op(1, 2) << std::endl;

    //函数指针
    MINUS mi = minus;
    op = std::function<int(int, int)>(mi);
    std::cout << op(1, 2) << std::endl;

    //lambda表达式
    op = std::function<int(int, int)> ([](int x, int y){return x * y;});
    std::cout << op(4, 2) << std::endl;

    //仿函数
    Divide d;
    op = std::function<int(int, int)> (d);
    std::cout << op(4, 2) << std::endl;

    std::map<std::string, std::function<int(int, int)>> mp{
            {"+", add},
            {"-", mi},
            {"*", [](int x, int y){return x * y;}},
            {"/", op}
    };

    std::cout << mp["/"](4, 2) << std::endl;

    return 0;
}
