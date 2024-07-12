#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e7 + 13;

std::vector<int> prime;
int d[N], st[N]{0};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), ans1(n, -1), ans2(n, -1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	int t = d[a[i]];
    	if (t == a[i]) {
    		continue;
    	}
    	while (a[i] % t == 0) a[i] /= t;
    	if (a[i] != 1) {
    		ans1[i] = t;
    		ans2[i] = a[i];
    	}
    }
    for (int i = 0; i < n; ++i) std::cout << ans1[i] << " \n"[i == n - 1];
   	for (int i = 0; i < n; ++i) std::cout << ans2[i] << " \n"[i == n - 1];

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    d[1] = 1;
    for (int i = 2; i < N; ++i) {
    	if (!st[i]) {
    		prime.push_back(i);
            d[i] = i;
    	}
    	for (auto p : prime) {
    		if (i * p >= N) break;
    		st[i * p] = 1;
    		d[i * p] = p;
    		if (i % p == 0) break;
    	}
    }

    solve();

    return 0;
}
