#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::stack<int>stk;
    std::set<int> st;
    
    int ans = 0, cur = 1;

    for(int i = 0; i < 2 * n; ++i) {
        std::string op;
        int val;
        std::cin >> op;
        if (op == "push") {
            std::cin >> val;
            stk.push(val);
        } else {
            if (stk.size()) {
                int t = stk.top();
                if (t != cur) {
                    ans++;
                }
                while (!stk.empty()) {
                    st.insert(stk.top());
                    stk.pop();
                }
            }
            st.erase(cur);
            cur++;
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
