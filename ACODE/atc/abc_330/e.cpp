#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    std::map<int, int> cnt;
    std::set<int> mex;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
    	std::cin >> a[i];
        cnt[a[i]]++;
        mex.insert(i);
    }
    mex.insert(N);

    for (int x : a) {
        if (cnt[x]) {
            mex.erase(x);
        }
    }
    while (Q--) {
        int i, x;
        std::cin >> i >> x;
        --i;
        if (--cnt[a[i]] == 0) {
            mex.insert(a[i]);
        }
        if (++cnt[x] == 1) {
            mex.erase(x);
        }
        a[i] = x;
        std::cout << *mex.begin() << "\n";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
