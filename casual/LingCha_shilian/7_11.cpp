#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

int shape[4][2] = {{3, 1}, {1, 3}, {2, 3}, {3, 2}};  // 依次对应题目描述的 4 种 L 形状

void solve() {
    std::string s[2];
    int n;
    std::cin >> s[0] >> s[1];
    n = s[0].size();
    
    //f[i][0/1/2/3] 表示当前行未被占据/上面占据/下面占据/全占据
    std::vector<i64> f(4, -inf);
    f[3] = 0;

    for (int i = 0; i < n; ++i) {
    	int cur = (s[0][i] >> 6 | s[1][i] >> 6 << 1);
    	std::vector<i64> g(4, -inf);   // 第 i 列的 X
    	g[cur] = std::max({f[0], f[1], f[2], f[3]});  // 不填 L
    	for (auto p : shape) {  // 填 L，枚举 L 形状
    		for (int pre = 0; pre < 4; ++pre) {  // 枚举第 i-1 列
    			if ((p[0] & pre) == 0 and (p[1] & cur) == 0) {  // 可以填 L
    				g[p[1] | cur] = std::max(g[p[1] | cur], f[pre] + 1);
    			}
    		}
    	}
    	f = g;
    }
    std::cout << std::max({f[0], f[1], f[2], f[3]});
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
