#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using namespace std;

bool isSpecial(string s, string t) {
	vector<int> cnt(26);
	bool ok = 0;
	for (auto c : s) {
		cnt[c - 'a']++;
	}
	for (auto c : t) {
		cnt[c - 'a']--;
	}
	int pos = 0, neg = 0;
	for (int i = 0; i < 26; ++i) {
		pos += cnt[i] > 0;
		neg += cnt[i] < 0;
	}
	return max(pos, neg) < 2;
}

vector<int> get(vector<pair<string, string>> a) {
	vector<int> ans;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		auto [s, t] = a[i];
		ans.push_back(isSpecial(s, t));
	}
	return ans;
}

void solve() {
	// auto res = get({{"safddadfs", "famafmss"}});
	auto res = get({{"abcee", "acdeedb"}, {"sljffsaje", "sljsje"}});
    for (auto x : res) {
    	std::cout << x << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
