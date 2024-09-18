#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a;
    std::string s;
    std::getline(std::cin, s);
	std::getline(std::cin, s);
	
	int pre = -1, im = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '-' or s[i] == ' ') {
			im = std::max(im, i - pre);
			a.push_back(i - pre);
			pre = i;
		}
	}

	a.push_back(int(s.size()) - pre - 1);
	im = std::max(im, int(s.size()) - pre - 1);

	auto check = [&](int k) {
		int count = 1, s = 0;
		for (auto x : a) {
			s += x;
			if (s > k) {
				++count;
				s = x;
				if (count > n) return false;
			} 
		}
		return true;
	};

	int l = im, r = s.size();

	while (l < r) {
		int mid = l + r >> 1;
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

    solve();

    return 0;
}