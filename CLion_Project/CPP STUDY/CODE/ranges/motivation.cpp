#include <bits/stdc++.h>

int main() {
    std::vector<int> v{1, 2, 4, 3, 6, 5, 8, 7};

//    std::ranges::sort(std::views::drop(v, 3));
    std::ranges::sort(v | std::views::reverse | std::views::drop(3));


    for (int x : v) {
        std::cout << x << " ";
    }

    return 0;
}
