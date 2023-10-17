#include <bits/stdc++.h>

//static_assert(sizeof(void *) != 8, "ÄãºÃ");

class cmp {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    std::vector a{1, 2, 5, 7, 6, 4};
    /*   std::sort(a.begin(), a.end(), cmp());*/

/*    int x =100, y = 100;
    auto f = [&x, y]()mutable {
        x = 50;
        y = 50;
        std::cout << x << " " << y << "\n";
    };
    f();
    std::cout << x << " " << y << "\n";
    return 0;*/

    std::for_each(a.begin(), a.end(), [](int &i){std::cout << i << " ";});

}
