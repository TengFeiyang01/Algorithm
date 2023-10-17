#include <bits/stdc++.h>

int add(int x, int y) {
    std::cout << "int(int x, int y)" << std::endl;
    return x + y;
}

double add(double x, double y) {
    std::cout << "double(double x, double y)" << std::endl;
    return x + y;
}

int main() {
    //函数指针强转
    auto obj = std::bind((int (*)(int, int))add, 10, 20);
    std::cout << obj() << std::endl;

    return 0;
}

#if 0
struct Pair {
    int data;
    double score;
};

class Mypair {
public:
    void func(int x, int y) {
        std::cout << "class Mypair void func()" << std::endl;
        std::cout << "x = " << x << " y = " << y << std::endl;
    }
};

int main() {
    Pair p{13, 2};
    //auto obj = std::bind(&Pair::data, p);
    //auto obj = std::bind(p, std::placeholders::_1, std::placeholders::_2);
    //std::cout << obj() << std::endl;

    Mypair mp;
    //绑定类内函数成员 需要传入类对象
    auto obj = std::bind(&Mypair::func, mp, 10, 20);
    obj();

    return 0;
}
#endif


#if 0
int divide(int x, int y) {
    return x / y;
}

int main() {
    auto div = std::bind(divide, 10, 3);
    std::cout << div() << std::endl;

    //auto div1 = std::bind(divide, 10,std::placeholders::_1);
    //std::placeholders::_x 会使用函数实参中的第x个参数替换
    auto div1 = std::bind(divide, std::placeholders::_1, 2);
    std::cout << div1(3) << std::endl;

    auto div3 = std::bind(divide, std::placeholders::_1, std::placeholders::_2);
    std::cout << div3(10, 5) << std::endl;

    auto div4 = std::bind(divide, std::placeholders::_2, std::placeholders::_1);
    std::cout << div4(10, 5) << std::endl;


    return 0;
}
#endif