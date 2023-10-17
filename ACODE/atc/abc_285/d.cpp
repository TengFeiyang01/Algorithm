#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<std::string, std::string>;
const int N = 1e5 + 13;

void solve() {
	int n, ok = 1;
    std::cin >> n;
    std::string a, b;
    std::stack<int> q;
    std::unordered_map<std::string, int> mp;
    
    std::vector<int> g[n * 2];
    int idx = 0;

    std::vector<int> idg(n * 2, 0);

   	int u, v;
    for (int i = 0; i < n; ++i) {
    	std::string a, b;
    	std::cin >> a >> b;
    	if (!mp.count(a)) mp[a] = idx++;
    	if (!mp.count(b)) mp[b] = idx++;
    	u = mp[a], v = mp[b];
    	g[u].pb(v);
/*    	std::cout << u << " ->" << v << "\n";*/
    	idg[v]++;
    }
/*    for (int i = 0; i < idx; ++i) {
    	std::cout << idg[i];
    }*/
    int cnt = 0;
    for (int i = 0; i < idx; ++i) {
    	if (idg[i] == 0) {
    		q.push(i);
    		cnt++;
    	}
    }

    while (sz(q)) {
    	int u = q.top();
    	q.pop();
    	for (int v : g[u]) {
    		if (--idg[v] == 0) q.push(v), cnt++;
    	}
    }
    ok = (cnt == idx);
    if (!ok) std::cout << "No";
    else std::cout << "Yes";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
