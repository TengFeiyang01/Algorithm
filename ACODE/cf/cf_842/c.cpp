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

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;
int n, m, nums[N];



void solve() {
    std::cin >> n;
    std::vector<int> v1(n + 1, -1), v2(n + 1, -1);
    int p[N]{0}, q[N]{0};
    
    for (int i = 1; i <= n; ++i) {
    	std::cin >> nums[i];
    }

    std::set<int> sp, sq;
    for (int i = 1; i <= n; ++i) {
        if (v1[nums[i]] == -1) {
            v1[nums[i]] = 1;
            p[i] = nums[i];
        } else if (v2[nums[i]] == -1) {
            v2[nums[i]] = 1;
            q[i] = nums[i];
        } else {
            //出现三次的直接失败
            std::cout << "NO\n";
            return;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (v1[i] == -1) sp.insert(i);
        if (v2[i] == -1) sq.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (p[i] == 0) {
            auto it = sp.upper_bound(q[i]);
            if (it == sp.begin()) {
                std::cout << "NO\n";
                return;
            } else {
                --it;
                p[i] = *it;
                sp.erase(it);
            }
        } else {
            auto it = sq.upper_bound(p[i]);
            if (it == sq.begin()) {
                std::cout << "NO\n";
                return;
            } else {
                --it;
                q[i] = *it;
                sq.erase(it);
            }
        }
    }
    std::cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        std::cout << p[i] << " ";
    }
    std::cout << "\n";
    for (int i = 1; i <= n; ++i) {
        std::cout << q[i] << " ";
    }
    std::cout << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
