#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    int a, b;
    std::priority_queue<PII> q;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a >> b;
    	if (a <= 10) {
    		q.push({b, i + 1});
    	}
    }
    std::cout << q.top().second << "\n";
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
