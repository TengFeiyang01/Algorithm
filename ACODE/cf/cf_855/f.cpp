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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	std::string s;
    	std::cin >> s;
    	for (auto c : s) {
    		int x = 1 << (c - 'a');
    		a[i] ^= x;
    		b[i] |= x;
    	}
    }
    std::vector<int> cc(1 << 26);
    ll ans = 0;
    int msk = (1 << 26) - 1;
    for (int t = 0; t < 26; ++t) {
    	for (int i = 0; i < n; ++i) {
            //枚举缺失的哪个字符 
    		if ((b[i] >> t) & 1) continue;
    		cc[a[i]]++;
            //a[i]中存的是当前这个字符中出现次数为奇数的字符的状态
            //a[i] ^ msk ==> 可知这是出去a[i]后的字符的状态 再 a[i] ^ msk ^ (1 << t) 即得到除去s[i]以及t这个字符后的情况，计数即可。
            //每次出现一个 都能和之前所有的加起来
    		ans += cc[msk ^ a[i] ^ (1 << t)];
    	} 
    	for (int i = 0; i < n; ++i) {
            //恢复现场
    		if ((b[i] >> t) & 1) continue;
    		cc[a[i]]--;
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
