#include <bits/stdc++.h>

#include <ranges>

int main() {
    std::vector vec{1, 2, 3, 4, 5, 6, 7, 8};

/*    auto res = vec | std::views::filter([](int n) { return n % 2 == 0; })
               | std::views::transform([](int n) { return n * 2; });

    for (auto x : res) {
        std::cout << x << "\n";
    }*/

    std::vector<int>::iterator itr;
/*    for (itr = vec.begin(); itr != vec.end(); itr++) {
        if (!(*itr % 2)) {
*//*            vec.erase(itr);
            //erase掉后 会itr已经++了 此时迭代器失效 it-- 可以解决
            --itr;*//*
            itr = vec.insert(itr, 100);
            //此时itr后续的迭代器都会失效
        } else {
            std::cout << *itr << std::endl;
        }
    }*/

    //逆序遍历 过滤掉奇数
    for (int it : std::ranges::reverse_view(vec) | std::views::filter([](int x){return x % 2 == 1;})) {
        std::cout << it << " ";
    }

    for (int it : std::ranges::reverse_view(vec)) {
        std::cout << it << " ";
    }

    return 0;
}
