#include <bits/stdc++.h>

//仿函数
class Cmp {
public:
    Cmp(bool b = true) : flag(b) {}

    bool operator()(int a, int b) {
        return flag ? a > b : a < b;
    }

private:
    bool flag;
};

class Pow {
public:
    template<typename T>
    T operator()(T x, int y) {
        T ans = 1;
        while (y) {
            if (y & 1) ans *= x;
            x *= x;
            y >>= 1;
        }
        return ans;
    }
};

int main() {
    int arr[] = {4, 2, 3, 0, 5, 1};
//    std::sort(arr, arr + 6);
    std::vector a(arr, arr + 6);
    std::sort(a.begin(), a.end(), Cmp(false));

    int x = 5;
    Pow pow;
//    std::cout << pow.operator()(x, 2) << std::endl;
    std::cout << pow(x, 2) << std::endl;
}

#if 0
class Pow {
public:
    template<typename T>
    T operator()(T x, int y) {
        T ans = 1;
        while (y) {
            if (y & 1) ans *= x;
            x *= x;
            y >>= 1;
        }
        return ans;
    }
};

int main() {
    int a = 5;

    Pow myPow;
    std::cout << myPow(a, 3) << "\n";

    return 0;
}
#endif