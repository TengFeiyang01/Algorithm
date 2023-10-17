#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::unordered_map<char, int> st;
    for (int i = 0; i < n; ++i) {
        st[s[i]]++;
    	if (st.size() == 3) {
    		std::cout << i + 1 << std::endl;
    		return;
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
