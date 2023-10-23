#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> a(n);
    int k = 0;
    for (auto &[x, y, z] : a) {
    	std::cin >> x >> y >> z;
        std::ranges::sort(a[k++]);
    }

    std::ranges::sort(a);

    std::map<int, int> Fenwick;

    auto upd = [&](int x, int val) {
        while (x <= 1e9) {
            if (!Fenwick.count(x) or Fenwick[x] > val) {
                Fenwick[x] = val;
            }
            x += x & -x;
        }
    };

    auto query = [&](int x) {
        int res = 1e9;
        while (x) {
            if (Fenwick.count(x) and Fenwick[x] < res) {
                res = Fenwick[x];
            }
            x -= x & -x;
        }
        return res;
    };

    bool ok = false;

    for (int i = 0; i < n;) {
        int st = i;
    	while (i < n and a[i][0] == a[st][0]) {
			if (query(a[i][1] - 1) < a[i][2]) {
				ok = true;
			}    		
			i++;
    	}

        while (st < i) {
            upd(a[st][1], a[st][2]);
            st++;
        }
    }
    std::cout << (ok ? "Yes\n" : "No\n");

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}