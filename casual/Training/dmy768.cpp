#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    std::vector<i64> cnt(n + 1), res1(m), res2(m);
    i64 ans = 0;

    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::array<int, 3>> qry(m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        qry[i] = {l, r, i};
        res2[i] = (r - l + 1LL) * (r - l) / 2;
    }	

    const int B = 500;
    std::sort(qry.begin(), qry.end(), [&](std::array<int, 3> &x, std::array<int, 3> &y) {
        int c = a[0] / B == 0;
    	if (x[0] / B != y[0] / B) return x[0] / B < y[0] / B;
    	return (c % 2 ? x[1] < y[1] : x[1] > y[1]);	
    });
    
    int l = 1, r = 0;
    auto add = [&](int x) {
    	ans += cnt[a[x]];
    	cnt[a[x]]++;
    };
    auto del = [&](int x) {
    	cnt[a[x]]--;
    	ans -= cnt[a[x]];
    };

    for (int i = 0; i < m; ++i) {
    	while (r < qry[i][1]) r++, add(r);
    	while (l > qry[i][0]) l--, add(l);
    	while (r > qry[i][1]) del(r), r--;
    	while (l < qry[i][0]) del(l), l++;
    	res1[qry[i][2]] = ans;
    }
    for (int i = 0; i < m; ++i) {
    	int g = std::__gcd(res1[i], res2[i]);
	    std::cout << res1[i] / g << "/" << res2[i] / g << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
