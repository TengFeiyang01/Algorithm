#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        pos[x].push_back(i);
    }
    int c1 = 0, v0 = 0;

    for (auto[v, p] : pos) {
        if (p.size() == 1) {
            c1++;
        } else if (p.size() > 2) {
            v0 = v;
        }
    }

    std::string ans(n, 'A');

    if (c1 % 2 > 0) {
        if (v0 == 0) {
            std::cout << "NO\n";
            return;
        }
        ans[pos[v0][0]] = 'B';
        c1++;
    }

    c1 /= 2;
    
    for (auto[_, p] : pos) {
        if (p.size() == 1) {
            if (c1 > 0) {
                c1--;
            } else {
                ans[p[0]] = 'B';
            }
        }
    }

    std::cout << "YES\n";
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
