#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int N;
    std::cin >> N;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; ++i) {
    	std::cin >> S[i];
    }
    i64 ans = 0;
    std::vector<int> rowCnt(N), colCnt(N);
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < N; ++j) {
    		rowCnt[i] += S[i][j] == 'o';
    		colCnt[j] += S[i][j] == 'o';
    	}
    }
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < N; ++j) {
    		if (S[i][j] == 'o') {
    			ans += i64(rowCnt[i] - 1) * (colCnt[j] - 1);
    		}
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
