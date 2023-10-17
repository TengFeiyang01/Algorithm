#include <bits/stdc++.h>

/*template<typename T1, typename T2>
auto func(T1 x, T2 y) ->decltype(x + y) {
    return x + y;
}*/

template<typename T1, typename T2>
decltype(auto) func(T1 x, T2 y) {
    return x + y;
}

int main() {
/*    auto i = 5;
    std::cout << sizeof i << "\n";

    auto j =  10000000000000;  //大于了INT_MAX 自动变为long long
    decltype(j) k;
    std::cout << sizeof j << "\n";
    */

    auto arr = {1, 2, 3, 4, 5, 6};

//    std::cout << sizeof(arr) << std::endl;

//    auto p = std::string("asasdk");

//    std::cout << sizeof(char *) << ": " << sizeof(std::string) << std::endl;
//    std::cout << sizeof(p) << std::endl;

    auto b = 3.0;

//    std::vector<decltype(b)> a(10);
//    std::cout << sizeof(a[0]) << std::endl;

    decltype([](int x){std::cout << x << std::endl;}) f;


    auto x = func(4, 3.0);

    return 0;
}
