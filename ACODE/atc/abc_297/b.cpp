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
    int x = -1, y, id;
    std::string s;
    std::cin >> s;
    for (int i = 0; i < 8; ++i) {
    	if (s[i] == 'B') {
    		if (x == -1) {
    			x = i;
    		} else {
    			y = i;
    		}
    	}
    	if (s[i] == 'K') {
    		id = i;
    	}
    }
    if (s.substr(0, id).find('R') != -1 and s.substr(id).find('R') != -1 and (x % 2) ^ (y % 2)) {
    	std::cout << "Yes";
    } else{
    	std::cout << "No";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
