#include <bits/stdc++.h>

//通过using给模板定义类型别名
template<typename T>
using MMap = std::map<int, T>;

int main() {
    MMap<std::string> ms;
    ms[1] = "daad";

    MMap<int> mi;
    mi[1] = 1;




    return 0;
}