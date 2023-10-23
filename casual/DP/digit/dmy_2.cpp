#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
//CF Round #739 (Div 3) F, Nearest Beautiful Number

void solve() {
    int n, k;
    std::vector<int> a(20);
    std::cin >> n >> k;
    int len = 0;
    while (n) {
    	a[++len] = n % 10;
    	n /= 10;
    }
    int st[20]{0};

    std::function<bool(int, bool, int, i64)> dfs = [&](int idx, bool down, int cnt, i64 num) ->bool {
    	if (!idx) {
    		std::cout << num << "\n";
    		return true;
    	}
    	for (int i = down ? 0 : a[idx]; i <= 9; ++i) {
    		st[i]++;
            int ncnt = cnt + (st[i] == 1);
            if (ncnt > k) {
                st[i]--;
                continue;
            }
            if (ncnt <= k and dfs(idx - 1, down or i > a[idx], ncnt, num * 10LL + i)) return true;
            st[i]--;
    	}
    	return false;
    };
    dfs(len, false, 0, 0);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
