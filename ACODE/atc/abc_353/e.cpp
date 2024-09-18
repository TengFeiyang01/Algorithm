#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 5e5 + 14;
int son[N][26], cnt[N], idx;

void insert(std::string s, int val) {
    int p = 0;
    for (auto u : s) {
    	u -= 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
	    cnt[p] += val;
    }
}

i64 query(std::string s) {
    int p = 0;
    i64 res = 0;
    for (auto u : s) {
    	u -= 'a';
        if (!son[p][u]) break;
        p = son[p][u];
        res += cnt[p];

    }
    return res;
}


void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	insert(a[i], 1);
    }
    i64 ans = 0;
    for (auto s : a) {
    	insert(s, -1);
    	ans += query(s);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
