#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::unordered_set<int> res, ors;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	std::unordered_set<int> tmp;
        for(auto it = ors.begin(); it != ors.end(); it++) {
            tmp.insert((*it) | x);    
        }

        tmp.insert(x);
        ors = tmp;
        for (auto it = tmp.begin(); it != tmp.end(); it++) {
        	res.insert(*it);
        }
    }
    std::cout << res.size() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
