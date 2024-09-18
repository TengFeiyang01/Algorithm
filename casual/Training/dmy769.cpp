#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n), freq(N), cnt(N);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    std::cin >> m;
    std::vector<int> res(m);
    std::vector<std::array<int, 4>> qry(m);
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        std::cin >> l >> r >> x;
        --l, --r;
        qry[i] = {l, r, x, i};
    }	

    const int B = 500;
    std::sort(qry.begin(), qry.end(), [&](std::array<int, 4> &x, std::array<int, 4> &y) {
        int c = a[0] / B == 0;
    	if (x[0] / B != y[0] / B) return x[0] / B < y[0] / B;
    	return (c % 2 ? x[1] < y[1] : x[1] > y[1]);	
    });
    
    int l = 0, r = -1;
    auto add = [&](int x) {
    	freq[cnt[a[x]]]--;
    	cnt[a[x]]++;
    	freq[cnt[a[x]]]++;
    };
    auto del = [&](int x) {
    	freq[cnt[a[x]]]--;
    	cnt[a[x]]--;
    	freq[cnt[a[x]]]++;
    };

    for (int i = 0; i < m; ++i) {
    	int k = qry[i][2];
    	while (r < qry[i][1]) r++, add(r);
    	while (l > qry[i][0]) l--, add(l);
    	while (r > qry[i][1]) del(r), r--;
    	while (l < qry[i][0]) del(l), l++;
    	res[qry[i][3]] = freq[k];
    }

    for (int i = 0; i < m; ++i) {
    	std::cout << res[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
