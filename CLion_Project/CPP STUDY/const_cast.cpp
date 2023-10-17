#include <bits/stdc++.h>


int main() {
    /*
    int a;
    const int &ra = a;
    a = 100;
    std::cout << a << std::endl;
    const_cast<int&> (ra) = 300;  //去const
    std::cout << a << std::endl;
    std::cout << ra << std::endl;

    const int *p = &a;
//    *p = 400;
    *const_cast<int*> (p) = 400;
    std::cout << *p << std::endl;
    std::cout << a << std::endl;
    std::cout << ra << std::endl;

    */
    const int a = 100;
    const int &ra = a;

    const_cast<int&> (ra) = 200;  //未定义行为
    std::cout << a << std::endl;
    std::cout << ra << std::endl;

    struct Data {
        int a;
    };
    const Data d = {40};
    const Data &rd = d;

    //基本数据类型不可修改 结构体可修改
    const_cast<Data&> (rd).a = 100;

    std::cout << d.a << std::endl;
    std::cout << rd.a << std::endl;


    return 0;
}
