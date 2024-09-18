#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, std::queue<int>> pos;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	pos[a[i]].push(i);
    }
    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
    	if (pos[a[i]].size() > 1 and pos[a[i]].front() == i) {
    		ans.push_back(pos[a[i]].front());
    		pos[a[i]].pop();
    		ans.push_back(pos[a[i]].front());
    		pos[a[i]].pop();
    	}
    }
    for (int x : ans){
    	std::cout << x + 1 << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
