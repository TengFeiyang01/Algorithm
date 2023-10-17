#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int A, B;
    std::cin >> A >> B;
    
    if (A < B) {
        std::swap(A, B);
    }
    
    std::cout << std::fixed << std::setprecision(10);
    if (A >= B / std::sqrt(3) * 2) {
        std::cout << B / std::sqrt(3) * 2 << "\n";
        return 0;
    }
    
    double x = 2 * std::sqrt(A * A - std::sqrt(3) * A * B + B * B);
    std::cout << x << "\n";
    
    return 0;
}