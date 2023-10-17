#include <bits/stdc++.h>

template<typename T>
int Compare(T a, T b) {
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    }
    return 0;
}

//特化版本 严格匹配 不可隐式转换
template<>
int Compare<const char *>(const char *a, const char *b) {
    std::cout << "template<>int Compare<const char *>(const char *a, const char *b)\n";
    return strcmp(a, b);
}

int main() {
/*    int a = 10, b = 20;
    std::cout << Compare(a, b) << "\n";*/

/*    std::string sa = "abc", sb = "Abc";
    std::cout << Compare(sa, sb) << "\n";*/

    const char *ca = "abc";
    const char *cb = "abcd";
//    std::cout << (int*)ca << "\n";  //0x7ff718926052
//    std::cout << (int*)cb << "\n";  //0x7ff718926056

    //比的是地址
    std::cout << Compare(ca, cb) << "\n";


    return 0;
}
