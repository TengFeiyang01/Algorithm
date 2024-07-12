#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int m, d, s = 0, cur = 0;
    for (int &x : a) {
    	std::cin >> x;
    	s += x;
    }
    s++;
    s /= 2;
    for (int i = 0; i < n; ++i) {
    	m++;
    	if (a[i] >= s) {
    		std::cout << m << " " << s << "\n";
    		break;
    	} else {
    		s -= a[i];
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
