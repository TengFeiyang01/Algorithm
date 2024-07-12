#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <numeric>
#include <cstring>
#include <map>
#include <unordered_map>

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e6 + 13;
int n, m, nums[N], get[N];

void solve() {
    std::cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        nums[i] = i;
        int s = 0, c = i;
        for (int j = i; j; j /= 10) {
            s += j % 10;
        }
        get[i] = s;
    }
    //预处理后查表O(1)
    std::sort(nums + 1, nums + 1 + n, [&](int x, int y){
        if (get[x] != get[y]) {
            return get[x] < get[y];
        }
        return x < y;
    });
    std::cout << nums[m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
