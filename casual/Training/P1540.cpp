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
int n, m, hash[1003]{0};

void solve() {
    std::queue<int> q;
    std::cin >> m >> n;
    int k, ans = 0;
    while (n--) {
        std::cin >> k;
        if (!hash[k]) {
            ++ans;
            q.push(k);
            hash[k] = 1;
            while (q.size() > m) {
                hash[q.front()] = 0;
                q.pop();
            }
        }
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
