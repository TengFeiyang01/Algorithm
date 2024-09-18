#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e5 + 3;

void solve() {
    int n, idx = -1;
    std::cin >> n >> n;
   	std::map<int, int> mp;
   	auto get = [&](int x) {
   		if (!mp.count(x)) {
   			mp[x] = ++idx;
   		}
   		return mp[x];
   	};
   	std::vector<i64> d(N), f(N);
   	std::iota(f.begin(), f.end(), 0);
   	int ans = n;

   	std::function<int(int)> find = [&](int x) {
   		if (f[x] != x) {
   			int rt = find(f[x]);
   			d[x] += d[f[x]];
   			f[x] = rt;
   		}
   		return f[x];
   	};

   	for (int i = 0; i < n; ++i) {
   		int x, y;
   		std::string s;
   		std::cin >> x >> y >> s;
   		x = get(x - 1), y = get(y);
   		int rx = find(x), ry = find(y);
   		int t = s == "odd";
   		if (rx == ry and abs(d[x] - d[y]) % 2 != t) {
   			ans = i;
   			break;
   		} else if (rx != ry) {
   			f[ry] = rx;
   			d[ry] = abs(d[x] - d[y] - t);
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
