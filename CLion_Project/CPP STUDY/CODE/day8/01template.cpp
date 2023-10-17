#include <bits/stdc++.h>

//函数模板 类型参数化  设置默认类型
//template<typename T = double>
template<typename T>
void swap(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}

//多个模板参数
template<typename T1, typename T2>
void swap(T1 &a, T2 &b) {
    T1 t = a;
    a = b;
    b = t;
}

class myType {
public:
    myType(int a, int b) : x(a), y(b) {}
    void dis() {
        std::cout << x << " " << y << "\n";
    }
private:
    int x;
    int y;
};

//函数模板 实例化  模板函数      模板函数的调用
//swap    ->   swap<int>    swap<int>(1, 2)


int main() {
/*    int a = 1, b = 2;
    swap(a, b);
    std::cout << a << " " << b;*/

/*    myType a(1, 2), b(2, 1);
    swap(a, b);
    a.dis();
    b.dis();*/

    int i = 1;
    double j = 2;
    swap(i, j);
    std::cout << i << " " << j << "\n";

    return 0;
}
