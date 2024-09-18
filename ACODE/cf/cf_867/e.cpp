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
不难发现 n 为奇数时无解,某个字母出现次数大于长度一半时无解.

然后我们找到所有冲突的位置,总数为s,并且找出冲突次数最多的字母数量.

如果冲突最多的字母不超过冲突总数的一半,那么显然一次可以减少两对冲突的位置,所以答案是 (s + 1) / 2.

否则操作次数就是冲突最多的字母的冲突数量.
*/

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if (n % 2) {
    	std::cout << "-1\n";
    	return;
    }
    int ans = 0;
    std::map<char, int> cnt;
    char mode;
    int same_cnt = 0, max_mode = 0;
    //内部消化
    for (int i = 0; i < n / 2; ++i) {
    	if (s[i] == s[n - i - 1]) {
    		cnt[s[i]] += 1;
    		same_cnt += 1;
    		if (cnt[s[i]] > max_mode) {
    			max_mode = cnt[s[i]];
    			mode = s[i];
    		}
    	}
    }

    for (int i = 0; i < n / 2; ++i) {
    	if (max_mode * 2 <= same_cnt) break;
    	if (s[i] != s[n - i - 1] and s[i] != mode and s[n - i - 1] != mode) {
    		same_cnt += 1;
    	}
    }
    ans += (same_cnt + 1) / 2;
    if (max_mode * 2 <= same_cnt) {
    	std::cout << ans << "\n";
    } else {
    	std::cout << "-1\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}


