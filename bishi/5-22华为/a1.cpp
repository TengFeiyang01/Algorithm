#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::vector<int> split(const std::string &line) {
    std::vector<int> result;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        if (!token.empty()) {
            result.push_back(stoi(token));
        }
    }
    return result;
}

std::vector<int> input() {
    std::string line;
    std::getline(std::cin, line);
    return split(line);
}

void solve() {
    auto a = input();
    auto b = input();
    int n = a.size(), m = b.size();
    int len = 0, st = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = 0;
            while (i + k < n && j + k < m && a[i + k] == b[j + k]) {
                k++;
            }
            if (k > len) {
                len = k;
                st = i;
            }
        }
    }

    if (len == 0) {
        std::cout << "-1\n";
        return;
    }

    for (int i = st; i < st + len; ++i) {
        if (i != st) std::cout << " ";
        std::cout << a[i];
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
