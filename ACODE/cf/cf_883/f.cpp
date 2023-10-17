#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> cnt(10), cnt1(10);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
    }

    auto ask = [&](int s, const std::vector<int> &d) {
		std::cout << "- " << d.size();
		for (auto x : d) std::cout << " " << x + 1;
		std::cout << std::endl;
		a.resize(s - int(d.size()));
    	for (int &x : a) std::cin >> x;
    };
	
	ask(n, std::vector<int>());

	for (int i = 0; i < n; ++i) {
		cnt1[a[i]]++;
	}

	int c = 0;
	for (int i = 1; i <= 9; ++i) {
		if (cnt1[i] == cnt[i] + 1) {
			c = i;
			break;
		}
	}
	if (c == 0) {
		ask(n, std::vector<int>());
		for (int i = 0; i <= 9; ++i) cnt1[i] = 0;
		for (int i = 0; i < n; ++i) cnt1[a[i]]++;
		for (int i = 1; i <= 9; ++i) {
			if (cnt1[i] == cnt[i] + 1) {
				c = i;
				break;
			}
		}
	}


	std::vector<int> del;
	for (int i = 0; i < n; ++i) {
		if (a[i] != c) del.push_back(i);
	}

	ask(n, del);
	
	int ans = 0;

	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != c) {
			ans = i + 1;
			break;
		}
	}

	if (ans == 0) {
		ask(a.size(), std::vector<int>());
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != c) {
				ans = i + 1;
				break;
			}
		}
	}

	std::cout << "! " << ans << std::endl;
}

int main() {
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
