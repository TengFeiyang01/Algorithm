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
    std::set<int> st;
    int n, q, cnt = 1;
    std::cin >> n >> q;

    int op, x;
    while (q--) {
    	std::cin >> op;
    	if (op == 1) {
    		st.insert(cnt++);
    	} else if (op == 2) {
    		std::cin >> x;
    		st.erase(x);
    	} else {
    		std::cout << *st.begin() << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
