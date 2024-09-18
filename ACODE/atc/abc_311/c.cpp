#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

//无向图找环

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	a[i]--;
    }
    std::vector<int> st(n);
    int i = 0;
    while (!st[i]) {
    	st[i] = 1;
    	i = a[i];
    }
    int j = i;
    std::vector<int> ans;
    do {
    	ans.push_back(j);
    	j = a[j];
    } while (j != i);
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
    	std::cout << ans[i] + 1 << " ";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
