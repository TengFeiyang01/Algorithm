#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::set<int>> st(N);
    for (int x, i = 0; i < N; ++i) {
    	std::cin >> x;
    	st[i].insert(x);
    }
    for (int i = 0; i < Q; ++i) {
    	int a, b;
    	std::cin >> a >> b;
    	--a, --b;
    	if (st[a].size() > st[b].size()) st[a].swap(st[b]);
    	for (int x : st[a]) st[b].insert(x);
        st[a].clear();
    	std::cout << st[b].size() << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
