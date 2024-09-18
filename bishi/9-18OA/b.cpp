#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

using namespace std;

int getMaxInformationGain(vector<string> dataSet, int max_common_featrues) {
	int n = dataSet.size(), ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int x = dataSet[i].size(), y = dataSet[j].size();
			vector<int> cnt1(26), cnt2(26);
			for (auto c : dataSet[i]) {
				cnt1[c - 'a']++;
			}
			for (auto c : dataSet[j]) {
				cnt2[c - 'a']++;
			}
			int res = 0;
			for (int k = 0; k < 26; ++k) {
				res += min(cnt1[k], cnt2[k]);
			}
			if (res <= max_common_featrues) {
				ans = std::max(ans, abs(x - y));
			}
			cout << x << "  " << y << "  " << res << endl;
		}
	}
	return ans;
}

void solve() {
    std::cout << getMaxInformationGain({"teojomo", "xrqyjzginr", "nzwacxxa", "drwudx"}, 2) << "\n";
    std::cout << getMaxInformationGain({"abofh", "ab", "mo"}, 1) << "\n";
    std::cout << getMaxInformationGain({"a", "bcdef"}, 1);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
