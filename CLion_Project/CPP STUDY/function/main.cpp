#include <iostream>
#include "func.h"

//局部静态变量
int count_calls() {
    static int cnt = 0;
    return ++cnt;
}

//值传递
void func1(int n) {
    std::cout << "func1 called!!!" << std::endl;
    n += 1;
}

//引用传递
void func2(int &n) {
    std::cout << "func2 called!!!" << std::endl;
    n += 1;
}

int main() {

    for (int i = 0; i < 1; ++i)
        std::cout << count_calls() << std::endl;

    //函数原型在func.h文件中
    //all_Permutation(3);

    //值传递和引用传递
    int x = 6;
    std::cout << x << std::endl;
    func1(x);
    std::cout << x << std::endl;
    //使用引用传递可以避免拷贝
    //使用const & 可以防止拷贝 并且不会对原变量修改
    func2(x);  //引用传递时，函数内使用的是传递的变量
    std::cout << x << std::endl;



    return 0;
}
