#include <bits/stdc++.h>

//int x = 100;

void foo() {
    std::cout << "foo" << std::endl;
}

//命名空间将全局的无名命名空间进行划分
namespace One {
    int x = 1;
}

namespace AnOther {
    int x = 2;
    namespace others {
        int x = 14;
    }
}

int main() {

    //int a = 3;
    //int a = 3;  //命名冲突

//    int x = 10;
//    std::cout << x << "\n";  //10 使用的是局部的变量
//    std::cout << ::x << std::endl;  // ::x 表示使用的是全局的x
//    ::foo(); //全局的无名命名空间的foo


    //使用方法一
    //std::cout << One::x << " " << AnOther::x << std::endl;  //使用的是不同命名空间内的变量
    {
        using One::x;  //使用的是One之内的x
        using namespace One; //导入namespace中的所有
        std::cout << x << "\n";
    }
    {
//        使用方法二
//        using AnOther::x;
//        std::cout << x << std::endl;

//        使用方法三
//        using namespace AnOther;
//        std::cout << x << std::endl;
    }
    //命名空间的嵌套使用
    std::cout << AnOther::others::x << std::endl;

    return 0;
}
