#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int M = 1e5 + 13;

//状态设计为 f[i]，表示在剩余 i 块石头时，当前操作者的胜负。
//有一个显然的结论：在剩余 0 块石头时，当前操作者必败。

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> a(N);
    std::vector<bool> f(K);
    for (int i = 0; i < N; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 1; i <= K; ++i) {
    	for (int x : a) {
    		f[i] = f[i] || i - x >= 0 and !f[i - x];
    	}
    }
    std::cout << (f[K] ? "First" : "Second") << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
