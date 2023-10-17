#include <bits/stdc++.h>
#include "myString.h"


int main() {
    //默认构造
    myString s1;
    //含参构造
    myString s2(" is great");
    //拷贝构造
    myString s3 = s2;

    myString s4 = "china";
    //赋值构造
    s3 = s4;

//    auto s5 = s4 + s2;
//    s5.dump();

    //能被赋值说明返回的不是 const myString
    (s4 += s2) = "abc";
    s4.dump();

    std::cout << s4.c_str() << std::endl;


    return 0;
}
