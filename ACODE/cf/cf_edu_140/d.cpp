#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
    std::string s;
    std::cin >> n;
    int a = 0, b = 0;
    std::cin >> s;
    for (auto c: s) {
    	if (c == '1') a = a * 2 + 1;
    	else b = b * 2 + 1;
    }
    for (int i = a; i < (1LL << n) - b; ++i)
    	std::cout << i + 1 << " ";
    std::cout << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
