#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;
int n, m, nums[N];



void solve() {
    int n;
    cin >> n;
    int l = inf, r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    if (is_sorted(nums, nums + n)) {
    	cout << nums[0] << "\n";
    	return;
    } else if (is_sorted(nums, nums + n, greater<int>())) {
        cout << nums[0] << "\n";
    }
    int k = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            k = max(k, nums[i] - (a[i] - a[i + 1]) / 2)
        }
    }


    for (int i = 0; i < n; ++i) nums[i] = abs(nums[i] - k);
    if (is_sorted(nums, nums + n)) {
        cout << k << "\n";
        return;
    }
    
    cout << "-1\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
