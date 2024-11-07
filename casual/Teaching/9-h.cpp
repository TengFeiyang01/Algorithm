#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void print(auto const& seq) {
    for (auto const& elem : seq) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

using namespace std;

class Solution {
public:
    vector<int> QuickSort(const vector<int> &numbers) {
        int n = numbers.size();
        vector<int> result, sufMin(n + 1, inf);
        // sufMin[n - 1] = numbers[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            sufMin[i] = std::min(sufMin[i + 1], numbers[i]);
        }

        int pre = -inf;
        for (int i = 1; i <= n; ++i) {
            if (pre <= numbers[i] and sufMin[i] == numbers[i]) {
                result.push_back(numbers[i]);
            }
            pre = std::max(numbers[i], pre);
        }

        std::sort(result.begin(), result.end());
        return result;
    }
};

// sum
// 1 2 3  4  5  6  7
// 1 3 6 10 15  21 28
// l:0, r:2
// A[l, r] = s[r] - s[l - 1] = s[2] - s[0-1] = s[2] - s[-1]

// diff

// a[0], a[1], a[2], a[3]
// a[0], a[1]-a[0], a[2]-a[1], a[3]-a[2]
// 给定数组
// n 次给 l, r, x  a[l, r] += x
// [0, 1]
// +x                 -x           

// d[l] += x
// d[r + 1] -= x

// a[0], a[1]-a[0], a[2]-a[1], a[3]-a[2]
// a[0]+x, a[1]+x,  a[2], a[3]
// a[0], a[1], a[2], a[4]
// 

// https://oi-wiki.org/basic/prefix-sum/
// https://leetcode.cn/circle/discuss/FfMCgb/
void solve() {
    int n;
    std::cin >> n;
    // preMax[i]: a[0, i] 的最大值
    // std::vector<int> a(n + 2), preMax(n + 2, -inf), sufMin(n + 2, inf);
    std::vector<int> a(n + 2), sufMin(n + 2, inf);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	// preMax[i] = std::max(preMax[i - 1], a[i]);
    }
    // pre[i-1] suf[i+1]
    for (int i = n; i >= 1; --i) {
    	sufMin[i] = std::min(sufMin[i + 1], a[i]);
    }
    int pre = -inf;
    std::vector<int> ans;
    for (int i = 1; i <= n; ++i) {
    	if (pre <= a[i] and sufMin[i] == a[i]) {
    		ans.push_back(a[i]);
    	}
        pre = std::max(a[i], pre);
    }

    std::sort(ans.begin(), ans.end());
    print(ans);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
