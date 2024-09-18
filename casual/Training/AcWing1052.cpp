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
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	int n, m;
	std::string t;
    std::cin >> n >> t;
    m = sz(t);
    t = " " + t;

    //f[i][j] 表示当前 已经 生成了i位 并且第i位匹配到字符串中是的位置是j时的方案数目。，
    vector f(n + 1, std::vector<int>(sz(t), 0));
    
    int ne[sz(t)]{0};

    int mod = 1e9 + 7;

    for (int i = 2, j = 0; i <= m; ++i) {
    	while (j && t[i] != t[j + 1]) j = ne[j];
    	if (t[i] == t[j + 1]) ++j;
    	ne[i] = j;
    }

    f[0][0] = 1;//已经匹配了0位,且匹配的子串的位置是0时的方案数为1;(初始化)

    for (int i = 0; i < n; ++i)//把第i位密码匹配到的子串位置都枚举一遍
    	for (int j = 0; j < m; ++j)//j表示第i位密码匹配到的位置,因为不能包含子串,所以不能匹配到m这个位置
    		for (char c = 'a'; c <= 'z'; ++c) {//把第i+1所有可能的字母都枚举一遍
    			int u = j;//寻找当第i+1的位置是k时,并且密码已经生成了第i位,匹配的子串的位置是j时,能跳到哪个位置
    			while (u && c != t[u + 1]) u = ne[u];
    			if (c == t[u + 1]) u++;
                //因为是从f[i][j](i+1的位置为k)跳到f[i+1][u]这个位置,所以f[i+1][u]=f[i+1][u]+f[i][j];
    			if (u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
    		}
    int res = 0;
    for (int i = 0; i < m; ++i) res = (res + f[n][i]) % mod;
    std::cout << res;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
