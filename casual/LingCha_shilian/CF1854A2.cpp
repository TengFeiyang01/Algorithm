#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int neg = 0, pos = 0, maxI = 0, minI = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (a[i] > 0) {
    		pos++;
    	} else if (a[i] < 0) {
    		neg++;
    	}
    	if (a[i] > a[maxI]) {
    		maxI = i;
    	}
    	if (a[i] < a[minI]) {
    		minI = i;
    	}
    }

    // 全大于0 全小于0
    //12+19 = 5+7
    std::vector<std::pair<int, int>> ans;
    auto makeNeg = [&]() {
    	for (int i = 0; i < n; ++i) {
    		if (a[i] > 0) {
    			ans.emplace_back(i, minI);
    		}
    	}
    	for (int i = n - 2; i >= 0; --i) {
    		ans.emplace_back(i, i + 1);
    	}
    };

    auto makePos = [&]() {
    	for (int i = 0; i < n; ++i) {
    		if (a[i] < 0) {
    			ans.emplace_back(i, maxI);
    		}
    	}
    	for (int i = 1; i < n; ++i) {
    		ans.emplace_back(i, i - 1);
    	}
    };

    if (a[maxI] >= -a[minI]) {
    	if (neg <= 12) {
    		makePos();
    	} else {
    		// 5 + 7 + 19
    		for (int i = 0; i < 5; ++i) {
    			ans.emplace_back(minI, minI);
    		}
    		makeNeg();
    	}
    } else {
    	// 12 + 19
    	if (pos <= 12) {
    		makeNeg();
    	} else {
    		for (int i = 0; i < 5; ++i) {
    			ans.emplace_back(maxI, maxI);
    		}
    		makePos();
    	}
    }
    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
    	std::cout << x + 1 << " " << 1 + y << "\n";
    }
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
