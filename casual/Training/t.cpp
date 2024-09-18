#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::multiset<int> st;
    int left = 1, right = 2, ans = 2;
    std::vector<int> a(n);

    for (int l = 0, r = 0; r < n; ++r) {
        std::cin >> a[r];
        st.insert(a[r]);
        auto it = st.begin();
        int x = *(it), y = *(++it), z = *(st.rbegin());

        while (st.size() >= 3 and x + y <= z) {
            st.erase(st.find(a[l]));
            l++;
            auto it = st.begin();

            x = *(st.begin()), y = *(++it), z = *(st.rbegin());
        }
        if (r - l + 1 > ans) {
            ans = r - l + 1;
            left = l + 1;
            right = r + 1;
        }
    }
    std::cout << left << " " << right << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}