#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 110;
const int M = 2e5 + 113;
int n, m;
int tr[M]{0};

int ds[N]{0};

void init() {
    for (int i = 0; i < 10; ++i) {
        ds[i] = i;
    }
    for (int i = 10; i < 100; ++i) {
        ds[i] = ds[i - 10] + 1;
    }
}

void add(int x, int v) {
    if (x > n) return;
    while (x <= n) {
        tr[x] += v;
        x += -x & x;
    }
}

int query(int x) {
    int ans = 0;
    while (x > 0) {
        ans += tr[x];
        x -= x & -x;
    }
    return ans;
}


int get(int num) {
    int ans = 0;
    while (num) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

void solve() {
    //多测清空
    memset(tr, 0, sizeof tr);
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b(n + 1);

    std::map<int, int> mp;


    for (int i = 1; i <= n; ++i) std::cin >> a[i];

	for (int i = 0; i < m; ++i) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int l, r;
			std::cin >> l >> r;
			add(l, 1);
			add(r + 1, -1);
		} else if (op == 2) {
			int id, cnt;
			std::cin >> id;
			int k = a[id];
			cnt = query(id);
            if (cnt == 0) {
                //没有修改过
                std::cout << a[id] << "\n";
            }
            else {
                cnt--;
                int ans;
                //第一次修改的值
                if (!mp.count(id)) {
                    ans = get(a[id]);
                    mp[id] = ans;
                } else {
                    ans = mp[id];
                }
                while (cnt--) {
                    ans = ds[ans];
                    if (ans < 10) break;
                }
                std::cout << ans << "\n";
            }
		}
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    init();
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
