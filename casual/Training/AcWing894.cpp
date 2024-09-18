#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

int n, ans = 0;
int sg[N];

int SG(int x) {
	if (~sg[x]) return sg[x];
	std::unordered_set<int> st;
	for (int i = 0; i < x; ++i)
		for (int j = 0; j <= i; ++j)
			st.insert(SG(i) ^ SG(j));
	for (int i = 0; ; ++i)
		if (!st.count(i)) 
			return sg[x] = i;
}


void solve() {
	memset(sg, -1, sizeof sg);
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int x; std::cin >> x;
		ans ^= SG(x);
	}	    
	if (ans) std::cout << "Yes\n";
	else std::cout << "No\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
