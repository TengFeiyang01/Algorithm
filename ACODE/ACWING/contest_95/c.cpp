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

//每次必定选最小的给对方 那么显然，我们在替换元素时，必定选择a2到an中，最小的元素给对方，并在之后的操作继续选择这个元素。这样，能确保最快让对方选到0。
//Bob没有选择优势，只能看他手头原始的a1元素。
//Alice有选择优势

void solve() {
    int n;
    ll x, c = 0;
    std::cin >> n;
    std::cin >> x;
    ll t = 1e13;
    for (int i = 1; i < n; ++i) {
        std::cin >> c;
        t = std::min(t, c);
    }
    if (x > t) {
    	std::cout << "Alice\n";
    } else {
    	std::cout << "Bob\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
