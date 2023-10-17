#include <iostream>
#include <vector>

template<typename T>
T sum(const std::initializer_list<T> &li) {
    T s = 0;
    for (const T &i : li) {
        s += i;
    }
    return s;
}

struct test {
    int a;
    std::vector<int> b;
};

int main() {
     test b = {1, {2, 3, 4, 5}};

    int s = sum({1, 2, 3, 4});  //变参
    std::cout << s << "\n";

    return 0;
}
