#include<bits/stdc++.h>

std::unordered_map<int, int> cache;
constexpr int N = 1000000;

int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        std::string c;
        int k;
        std::cin >> c >> k;
        if (c == "A") {
                cache[k] = i;
            if (cache.size() > n) {
                int k = N;
                int q = -1;
                for (auto t: cache) {
                    if (t.second < k) {
                        k = t.second;
                        q = t.first;
                    }
                }
                cache.erase(q);
            }
        } else if (c == "Q" and cache[k] > 0) {
            cache[k] = i;
        } else {
            cache.erase(k);
        }
    }

    std::vector<int> ans;
    for (auto t: cache) {
        ans.push_back(t.first);
    }
    std::sort(ans.begin(), ans.end());
    n = ans.size();
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}