#include <bits/stdc++.h>
 
using i64 = long long;
const i64 inf = 1LL << 60;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
   	while (std::cin >> n >> m) {
        if (n == -1 and m == -1) break;
   		int s = 0;
   		std::vector<std::pair<int, int>> items[40];
   		for (int i = 0; i < n; ++i) {
   			int w, v;
   			std::cin >> w >> v;
   			int lev = __builtin_ctz(w);
   			w >>= lev;
   			items[lev].push_back({w, v});
   			s += w;
   		}
   		std::vector<i64> f(2010, -inf), g(2010);
   		f[0] = 0; //>=2^31 的背包 
   		for (int i = 30; i >= 0; --i) {
   			//i + 1 -> i
   			for (int j = 0; j <= s; ++j) {
                g[j] = f[j];
                f[j] = -inf;
            }
   			int d = (m >> i) & 1;
   			for (int j = 0; j <= s; ++j) { //j件 2^i 的物品
                //如果当前这一位是 1 原本的101的背包 变为 1011 背包 （容量增加了）
   				f[std::min(2 * j + d, s)] = std::max(f[std::min(2 * j + d, s)], g[j]);
   			}
   			for (int j = s - 1; j >= 0; --j) f[j] = std::max(f[j], f[j + 1]);
   			for (auto p : items[i]) {
   				int x = p.first, y = p.second;
   				for (int j = x; j <= s; ++j) //剩余容量
   					f[j - x] = std::max(f[j - x], f[j] + y);
   			}
   		}
   		std::cout << f[0] << "\n";
   	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
