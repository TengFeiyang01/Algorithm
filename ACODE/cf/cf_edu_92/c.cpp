#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

/*
    要有 s2 s3 ... sn s1 == sn s1 s2 ... sn-1
    对应位置相等得： s2 = sn, s1 = s3 s2 = s4 ... 
    猜测 要么答案的 s 仅包含一个字符c，要么是形如 “abab...ab” 的偶数串的循环
    对于第一种情况 计数即可
    对于第二种情况 我们可以枚举 a和b 统计循环节的长度len 答案为n-len
*/


void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    int ans = n - 2;
   	std::vector<int> num(10);
   	for (char c : s) {
   		c -= '0';
   		num[c]++;
   	}
   	for (int i = 0; i < 10; ++i) {
   		ans = std::min(ans, n - num[i]);
   	}


   	for (int i = 0; i < 10; ++i)
   		for (int j = 0; j < 10; ++j) {
   			if (i == j) continue;
   			int cnt = 0, cur = i, ok = 1;
   			for (int k = 0; k < n; ++k) {
                int t = s[k] - '0';
                if (ok and t == i) {
                    cnt++;
                    ok = 0;
                }
                if (!ok and t == j) {
                    cnt++;
                    ok = 1;
                }
            }
   			cnt = cnt / 2 * 2;
   			ans = std::min(ans, n - cnt);
   		}
   	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
