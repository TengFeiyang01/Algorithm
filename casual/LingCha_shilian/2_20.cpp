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
#include <stack>
#include <numeric>
#include <cmath>

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back

#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

int cnt[26]{0};

/*
https://codeforces.com/contest/600/submission/97136757

提示 1：修改出现次数为奇数的字符。

提示 2：为了让字典序尽量小，这些奇数字母也要对应匹配。设 adef 出现了奇数次，那么把 f 改成 a，e 改成 d。 

提示 3：注意有奇数个奇数的情况，此时回文中心是不需要修改的。
*/

void solve() {
    std::string s;
    std::cin >> s;
    for (char c : s) cnt[c - 'a']++;
    std::vector<int> p;

    for (int i = 0; i < 26; ++i) {
        if (cnt[i] % 2 == 1) {
            p.pb(i);
        }
    }
    for (int i = 0, j = sz(p) - 1; i < j; ++i) {
        cnt[p[i]]++;
        cnt[p[j]]--;
        --j;
    }
    //前半部分
    for (int i = 0; i < 26; ++i) {
        std::cout << std::string(cnt[i] / 2, 'a' + i);
    }
    //奇数个奇数的情况，输出
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] % 2) {
            std::cout << char('a' + i);
        }
    }
    for (int i = 25; i >= 0; --i) {
        if (cnt[i]) {
            std::cout << std::string(cnt[i] / 2, 'a' + i);
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
