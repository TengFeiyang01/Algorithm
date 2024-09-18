#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int solution( vector<int> digits) {
	int ans = 0, n = digits.size();
	for (int i = 0; i < n; ++i) {
		ans = max(ans, digits[i]);
		for (int j = i + 1; j < n; ++j) {
			ans = max(ans, digits[i] * 10 + digits[j]);
			for (int k = j + 1; k < n; ++k) {
				ans = max(ans, digits[i] * 100 + digits[j] * 10 + digits[k]);
			}
		}
	}
	return ans;
}

class Solution {
    public static int solution(int[] digits) {
        int ans = 0, n = digits.length;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, digits[i]);
            for (int j = i + 1; j < n; ++j) {
                ans = Math.max(ans, digits[i] * 10 + digits[j]);
                for (int k = j + 1; k < n; ++k) {
                    ans = Math.max(ans, digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
        return ans;
    }
}

void solve() {
    
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
