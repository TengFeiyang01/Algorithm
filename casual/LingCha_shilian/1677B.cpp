#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::vector<bool> col(m);
    int col1 = 0;
    int window = 0;
    std::vector<int> f(m);
   	for (int i = 0; i < n * m; ++i) {
   		if (s[i] == '1' and !col[i % m]) {
   			col[i % m] = true;
   			col1++;
   		}
   		window += int(s[i] & 1);
   		if (i >= m) window -= int(s[i - m] & 1);
   		if (window) f[i % m]++;
   		std::cout << col1 + f[i % m] << " ";
   	}
   	std::cout << "\n";
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
