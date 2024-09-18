#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using namespace std;

class Solution {
public:
	int solution(string s) {
		int n = s.size();
		for (int len = 1; len <= n; ++len) {
			std::map<string, int> cnt;
			for (int j = 0; j + len - 1 < n; ++j) {
				cnt[s.substr(j, len)]++;
			}
			for (auto [k, v] : cnt) {
				if (v == 1) {
					return k.size();
				}
			}
		}
	}
};

void solve() {
    Solution a;
    std::cout << a.solution("abaaba") << "\n";
    std::cout << a.solution("zyzyzyz");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
