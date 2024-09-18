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
int n, m, nums[N]{0};

void solve() {
	int t;
    std::cin >> t;
    std::set<int> s;

    for (int i = 1; i <= t; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        s.insert(a);
        nums[a] += b - c;
    }
    for (int i = 1; i <= (int)s.size(); ++i) {
        if (nums[i] >= 0) {
            std::cout << "LIVE\n";
        } else {
            std::cout << "DEAD\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
