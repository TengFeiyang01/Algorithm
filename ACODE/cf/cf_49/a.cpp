#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::string s;
    std::cin >> s >> n;

    std::vector<std::string> t(n);

    for (int i = 0; i < n; ++i) {
    	std::cin >> t[i];
    }
    bool ok = true;
    std::vector<std::string> a;
    
    for (auto c : t) {
    	if (c.find(s) == 0) {
    		a.push_back(c);
    	}
    }
    if (a.empty()) {
    	std::cout << s << "\n";
    } else {
    	std::sort(a.begin(), a.end());
    	std::cout << a[0] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
  
    solve();

    return 0;
}
