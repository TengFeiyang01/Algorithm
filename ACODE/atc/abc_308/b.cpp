#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s[n];
    std::string t[m];
    for (auto &x : s) std::cin >> x;
    for (auto &x : t) std::cin >> x;
    int p0;
    std::cin >> p0;
    std::vector<int> a(m);
	for (int &x : a) std::cin >> x;
	i64 tot = 0;
	std::map<std::string, int> id;
	for (int i = 0; i < m; ++i) {
		id[t[i]] = a[i];
	}
	for (auto c : s) {
		if (id.count(c)) tot += id[c];
		else tot += p0;
	}
	std::cout << tot << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
