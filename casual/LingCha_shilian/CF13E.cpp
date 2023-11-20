#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int B = 500;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::vector<std::array<int, 2>> data(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    auto f = [&](int i) ->void {
    	if (a[i] + i >= n or (a[i] + i) / B != i / B) {
    		data[i] = {i, 0};
    	} else {
    		data[i] = data[i + a[i]];
    		data[i][1]++;
    	}
    };
    for (int i = n - 1; i >= 0; --i) {
    	f(i);
    }
    for (int i = 0; i < m; ++i) {
    	int op, x, y;
    	std::cin >> op >> x;
    	--x;
    	if (op == 0) {
    		std::cin >> y;
    		a[x] = y;
            for (int i = x; i >= x - x % B; --i) {
                f(i);
            }
    	} else {
    		int jump = 0, last;
    		for (; x < n; x = last + a[last]) {
    			jump += data[x][1] + 1;
    			last = data[x][0];
    		}
    		std::cout << last + 1 << " " << jump << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
