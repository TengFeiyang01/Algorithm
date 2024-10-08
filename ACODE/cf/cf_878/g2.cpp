#include <bits/stdc++.h>

using i64 = long long;

constexpr int B = 400;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int x;
    std::cin >> x;
    
    int N = x;
    
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    
    for (int i = 0; i < B; i++) {
        std::cout << "+ " << rng() % 1000000000 + 1 << std::endl;
        std::cin >> x;
        N = std::max(N, x);
    }
    
    int C = (1000 - B) / 2;
    
    std::map<int, int> f;
    f[x] = 0;
    
    for (int i = 1; i < C; i++) {
        std::cout << "- " << 1 << std::endl;
        std::cin >> x;
        if (!f.count(x)) {
            f[x] = i;
        }
    }
        
    std::cout << "+ " << C - 1 + N << std::endl;
    std::cin >> x;
    int n = N;
    while (!f.count(x)) {
        std::cout << "+ " << C << std::endl;
        std::cin >> x;
        n += C;
    }
    n += f[x];
    std::cout << "! " << n << std::endl;

    return 0;
}
