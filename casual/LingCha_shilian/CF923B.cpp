#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;
    i64 s = 0;
    for (int t; auto x : a) {
        std::cin >> t;
        pq.push(s + x); 
        i64 res = 0;
        while (pq.size() and pq.top() <= s + t) {
            res += pq.top() - s;
            pq.pop();
        }
        res += i64(pq.size()) * t;
        std::cout << res << " ";
        s += t;
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
