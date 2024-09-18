#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, C;
    std::cin >> N >> C;
    
    int M;
    std::cin >> M;
    
    std::map<int, i64> f;
    f[1] = 0;
    
    auto get = [&](int x) {
        auto it = f.lower_bound(x);
        i64 ans = -1E18;
        if (it != f.end()) {
            ans = it->second - 1LL * (it->first - x) * C;
        }
        if (it != f.begin()) {
            ans = std::max(ans, std::prev(it)->second - 1LL * (x - std::prev(it)->first) * C);
        }
        return ans;
    };
    
    i64 ans = 0;
    for (int i = 0; i < M; i++) {
        int T;
        i64 P;
        std::cin >> T >> P;
        
        i64 res = get(T) + P;
        f[T] = res;
        ans = std::max(ans, res);
        auto it = f.find(T);
        while (it != f.begin() && std::prev(it)->second < res - 1LL * (T - std::prev(it)->first) * C) {
            f.erase(std::prev(it));
        }
        auto r = std::next(it);
        while (r != f.end() && r->second < res - 1LL * (r->first - T) * C) {
            r = f.erase(r);
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}
