#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::string s;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::cin >> s;
    auto mex = [&](int x, int y, int z) ->int {
        for (int i = 0; i < 3; ++i) {
            if (x != i and y != i and z != i) return i;
        }
        return 3;
    };
    //cnt_r[i][j] 表示 i 右侧为 'X' 且对应的 a[i] 为 j 的个数
    //cnt_l[i][j] 表示 i 左侧侧为 'M' 且对应的 a[i] 为 j 的个数
    //我们枚举中间的 'E' 然后计算每一类mex的值

    // std::vector cnt_l(n + 1, std::vector(3, 0));
    // std::vector cnt_r(n + 1, std::vector(3, 0));

    std::vector<int> cnt_l(3), cnt_r(3);
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'X') ++cnt_r[a[i]];
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'X') {
            --cnt_r[a[i]];
        }
        if (s[i] == 'E') {
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k) 
                    ans += i64(cnt_l[j]) * cnt_r[k] * mex(j, a[i], k);
        }
        if (s[i] == 'M') {
            ++cnt_l[a[i]];
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
