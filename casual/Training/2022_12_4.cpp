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

using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m;

void rev(std::string &s,int l, int r) {
    char t;
    while (l < r) {
        t = s[l];
        s[l] = s[r];
        s[r] = t;
        l++;
        r--;
    }
}

void solve() {
    std::string s;
    std::cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        int l, r, k;
        std::cin >> l >> r >> k;
        l--, r--;
        k = k % (r - l + 1);
        rev(s, r - k + 1, r);
        rev(s, l, r - k);
        rev(s, l, r);
    }
    std::cout << s << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
