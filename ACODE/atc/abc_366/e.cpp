#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int N, D;
    std::cin >> N >> D;
    std::vector<int> x(N), y(N);
    for (int i = 0; i < N; ++i) {
    	std::cin >> x[i] >> y[i];
    }
    
    auto get = [&](std::vector<int> &a) {
    	std::ranges::sort(a);
    	int r = 2e6;
    	std::vector<i64> dis;
    	i64 pre = 0, suf = std::accumulate(a.begin(), a.end(), 0LL);
    	int j = 0;
    	for (int i = -r; i <= r; ++i) {
    		i64 sum = 0;
    		while (j < N and a[j] < i) {
    			pre += a[j];
    			suf -= a[j];
    			j++;
    		}
    		sum = 1LL * j * i - pre + suf - 1LL * (N - j) * i;
    		dis.push_back(sum);
    	}
    	std::ranges::sort(dis);
    	return dis;
    };

    auto p = get(x), q = get(y);

    i64 ans = 0;
    int j = q.size() - 1;
    for (auto x : p) {
    	while (j >= 0 and q[j] + x > D) {
    		--j;
    	}
    	ans += j + 1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
