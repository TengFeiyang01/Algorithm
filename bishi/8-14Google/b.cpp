#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int solution(vector<int> A) {
	long long ans = A[0];
	for (int i = 1; i < n; ++i) {
		if (A[i] - A[i - 1] > 0) {
			ans += A[i] - A[i - 1];
		}
	}
	return ans
}

public class Solution {
    public int solution(int[] A) {
        int ans = A[0];
        for (int i = 1; i < A.length; ++i) {
            if (A[i] - A[i - 1] > 0) {
                ans += A[i] - A[i - 1];
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
