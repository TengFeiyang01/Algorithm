#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;

    auto check = [&](i64 sum) -> bool {
    	std::vector<int> pre(n + 1), suf(n + 1);
    	std::priority_queue<int> pq;
    	int mx = 0;
        i64 cur = sum;
    	//pre代表当前和为sum时，前i个数中最多能选出的数的个数
        //suf代表后缀的个数
        for (int i = 0; i < n; ++i) {
    		cur -= a[i];
    		pq.push(a[i]);
    		if (cur < 0) {
    			cur += pq.top();
    			pq.pop();
    		}
    		pre[i + 1] = (int)pq.size();
    	}
        cur = sum;
        pq = std::priority_queue<int>();
        for (int i = 0; i < n; ++i) {
            int x = a[n - i - 1];
            cur -= x;
            pq.push(x);
            if (cur < 0) {
                cur += pq.top();
                pq.pop();
            }
            suf[i + 1] = std::max(suf[i], (int)pq.size());
        }
        for (int i = 1; i <= n; ++i) {
            if (pre[i] + suf[n - i] >= k) {
                return true;
            }
        }
        return false;
    };
    i64 l = 0, r = 1e15;
    while (l < r) {
        i64 mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
