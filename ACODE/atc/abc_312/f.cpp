#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }

int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a, b, c;
	for (int i = 0; i < n; i++) {
		int t; ll x;
		cin >> t >> x;
		if (t == 0) a.push_back(x);
		else if (t == 1) b.push_back(x);
		else c.push_back(x);
	}
	sort(a.begin(), a.end(), greater<>());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	vector<ll> x(n + 1), y(n + 1);
	for (int i = 0; i < n; i++) {
		if (i < a.size()) x[i + 1] = x[i] + a[i];
		else x[i + 1] = x[i];
	}
	//x[i] 是选前i个最大的0的价值
	//y[i] 是1和2的和是i的最大价值
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (b.empty()) y[i + 1] = y[i];
		else if (r == 0) {
			if (!c.empty()) {
				r += c.back();
				c.pop_back();
			}
			y[i + 1] = y[i];
		}
		else {
			r--;
			y[i + 1] = y[i] + b.back();
			b.pop_back();
		}
	}
	ll ans = 0;
	for (int i = 0; i <= m; i++) chmax(ans, x[i] + y[m - i]);
	cout << ans << endl;
}
