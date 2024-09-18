#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<std::pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U--, V--;
        adj[U].emplace_back(V, W);
        adj[V].emplace_back(U, W);
    }
    
    int K;
    std::cin >> K;
    
    std::vector<int> A(K);
    for (int i = 0; i < K; i++) {
        std::cin >> A[i];
        A[i]--;
    }
    
    int D;
    std::cin >> D;
    
    std::vector<int> X(D + 1);
    for (int i = 1; i <= D; i++) {
        std::cin >> X[i];
    }
    
    std::vector<int> f(N, -1);
    std::vector<int> ans(N, -1);
    std::priority_queue<std::pair<int, int>> q1;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q2;
    for (int i = 0; i < K; i++) {
        q2.emplace(0, A[i]);
    }
    for (int i = 0; i <= D; i++) {
        while (!q2.empty()) {
            auto [d, x] = q2.top();
            
            if (d > X[i]) {
                break;
            }
            
            q1.emplace(X[i] - d, x);
            q2.pop();
        }
        
        while (!q1.empty()) {
            auto [d, x] = q1.top();
            q1.pop();
            
            if (f[x] != -1) {
                continue;
            }
            f[x] = d;
            ans[x] = i;
            
            for (auto [y, w] : adj[x]) {
                q2.emplace(w, y);
                if (d >= w) {
                    q1.emplace(d - w, y);
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << "\n";
    }
    
    return 0;
}
