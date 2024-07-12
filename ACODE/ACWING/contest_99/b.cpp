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
    std::map<int, int> buy, sale;
    int n, s;
    char op;
    int p, q;
    std::cin >> n >> s;
    for (int i = 0; i < n; ++i) {
    	std::cin >> op >> p >> q;
    	if (op == 'B') {
    		buy[p] += q;
    	} else {
    		sale[p] += q;
    	}
    }

    std::vector<PII> b, a;
    for (auto[p, q] : buy) {
    	b.emplace_back(p, q);
    }
    for (auto[p, q] : sale) {
    	a.emplace_back(p, q);
    }

    for (int i = std::min(sz(a) - 1, s - 1); i >= 0; --i) {
    	auto[p, q] = a[i];
    	std::cout << "S " << p << " " << q << "\n";

    }

    for (int i = b.size() - 1; i >= 0 and s--; --i) {
    	auto[p, q] = b[i];
    	std::cout << "B " << p << " " << q << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
	solve();

    return 0;
}
