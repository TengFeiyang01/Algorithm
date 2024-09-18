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
using ll = long long;
const ll inf = 922337203685477;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    ll Q, a, b;
    std::cin >> Q >> a >> b;
    
    std::set<ll> st;

    st.insert(a + b);


    while (Q--) {
    	int t;
    	std::cin >>t >> a >> b;
    	if (t == 1) {
    		st.insert(a + b);
        } else if (t == 2) {
            for (auto it = st.begin(); it != st.end(); ++it) {
               // std::cout << *it << " ";
            }
            //l [a, b] r
            auto ita = st.lower_bound(a);
            if (ita != st.end() && (*ita <= b || *ita == a)) {
                std::cout << "0\n";
            }

    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
