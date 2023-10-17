#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::map<char, int> cnt;
    for (auto c : s) {
    	cnt[c]++;
    }
    int t = n / 3;
    for (int i = 0; i < n; ++i) {
    	if (cnt[s[i]] > t) {
    		for (auto ch = '0'; ch < s[i]; ++ch) {
    			if (cnt[ch] < t) {
    				cnt[s[i]]--;
    				cnt[ch]++;
                    s[i] = ch;
    			}
    		}
    	}
    }
    for (int i = n - 1; i >= 0; --i) {
    	if (cnt[s[i]] > t) {
    		for (auto ch = '2'; ch >= s[i]; --ch) {
    			if (cnt[ch] < t) {
    				cnt[s[i]]--;
                    s[i] = ch;
    				cnt[ch]++;
    			}
    		}
    	}
    }
    std::cout << s << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
