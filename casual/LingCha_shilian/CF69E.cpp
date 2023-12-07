#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::map<int, int> freq;
    std::priority_queue<int> pq;

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (++freq[a[i]] == 1) {
    		pq.push(a[i]);
    	} 
    	if (i >= k - 1) {
    		while (pq.size() and freq[pq.top()] != 1) {
    			pq.pop();
    		}
    		if (pq.empty()) {
	    		std::cout << "Nothing\n";
	    	} else {
	    		std::cout << pq.top() << "\n";
	    	}
	    	// 出去的时候也要入队 因为可能出去后 当前窗口内剩余的元素成为了最大值
	    	if (--freq[a[i - k + 1]] == 1) {
	    		pq.push(a[i - k + 1]);
	    	}
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}