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
    std::string s;
    std::string t;
    std::cin >> s >> t;

    int a1 = count(s.begin(), s.end() , '@');
    int a2 = count(t.begin(), t.end() , '@');
    int cnt[26]{0};
    for (char c : s) {
    	if (c == '@') continue;
    	c -= 'a';
    	cnt[c]++;
    }
    for (char c : t) {
    	if (c == '@') continue;
    	c -= 'a';
    	cnt[c]--;
    }

    
    bool ok = 1;
    std::string z = "atcoder";
    std::unordered_set<int> st;
    for (char c : z) {
    	c -= 'a';
    	st.insert(c);
    }
    int tot = a1 + a2;
    for (int i = 0; i < 26; ++i) {
    	if (abs(cnt[i])) {
    		if (!st.count(i)) {
    			ok = 0;
    			break;
    		} else {
                tot -= abs(cnt[i]);
            }
    	}
    }
    if (tot < 0) ok = 0;
    if (ok and tot % 2 == 0) {
    	std::cout << "Yes";
    } else {
    	std::cout << "No";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
