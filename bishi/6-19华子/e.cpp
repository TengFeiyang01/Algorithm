#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> nums(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> nums[i];
    }

    int ans = 0;

    for (int i = 1, j; i < n; i++) {
		if (nums[i - 1] > nums[i]) {
			j = i;
			i64 x = nums[i - 1] - nums[i];
			while (j < n && nums[j] > nums[j - 1]) {
				nums[j] += x;
				j++;
			}
			ans++;
		} 	
    }
    
    // return ans;


    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
