#include <bits/stdc++.h>
 
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
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &v : a) std::cin >> v;
    if (n == 1) {
    	std::cout << "-1\n";
    	return;
    }
    auto ispa = [&](std::vector<int> a)->bool {
    	for (int i = 2; i < sz(a); ++i)
    		if (a[i] - a[i - 1] != a[1] - a[0])
    			return false;
    	return true;
    };
    std::vector<int> ans;
    std::sort(all(a));
    if (ispa(a)) {
    	if (a[0] == a[1]) {
    		ans.push_back(a[0]);
    	} else {
    		ans.push_back(2 * a[0] - a[1]);
    		ans.push_back(2 * a[n - 1] - a[n - 2]);
    		if (n == 2 and (a[0] + a[1]) % 2 == 0)
    			ans.push_back((a[0] + a[1]) / 2);
    	}
    } else {
    	auto b = a;
    	b.insert(b.begin() + 1, (a[0] + a[1]) / 2);
    	if ((a[0] + a[1]) % 2 == 0 and ispa(b)) ans.push_back((a[0] + a[1]) / 2);
    	int d0 = a[1] - a[0];
    	for (int i = 2; i < n; ++i) {
    		int d = a[i] - a[i - 1];
    		if (d != d0) {
    			if (d == d0 * 2) {
    				auto c = a;
    				c.insert(c.begin() + i, (a[i - 1] + a[i]) / 2);
    				if (ispa(c)) ans.push_back((a[i - 1] + a[i]) / 2);
    			}
    			break;
    		}
    	}
    }
    std::sort(all(ans));
    std::cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
    	std::cout << ans[i] << " \n"[i == sz(ans)];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
