#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
    	
    }


}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
