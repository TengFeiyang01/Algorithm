#include <iostream>
#include <vector>
#include <algorithm>

bool find(const std::vector<int>& alls, int x, int l, int r) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (x == alls[mid]) {
            return true;
        } else if (x > alls[mid]) {
            std::cout << "R";
            l = mid + 1;
        } else {
            std::cout << "L";
            r = mid - 1;
        }
    }
    return false;
}

std::vector<int> input() {
    std::vector<int> a;
    int s;
    while(std::cin >> s) {
        a.push_back(s);
        if(std::cin.get() != ' ') break;
    }
    return a;
}


int main() {
    auto alls = input();
    std::sort(alls.begin(), alls.end());
    int n = alls.size();
    int x;
    std::cin >> x;

    std::cout << "S";
    bool ans = find(alls, x, 0, n - 1);
    if (ans) {
        std::cout << "Y\n";
    } else {
        std::cout << "N\n";
    }
    return 0;
}
