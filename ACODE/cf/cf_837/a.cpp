#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
 
using namespace std;
using ll = long long;
const int N = 200005;
ll n, m, C[N];
 
emplace_back(a ,b);


void solve() {
    cin >> n;
    map<int, int> cnt;
    for (int i = 1; i <= n; ++i) cin >> C[i], cnt[C[i]]++;
    auto t1 = cnt.begin();
    auto t2 = cnt.rbegin();
 
    if (cnt.size() == 1) {
        cout << n * (n - 1) << "\n";
    } else {
        //不开ll见祖宗
        cout << 1LL * t1->second * t2->second * 2 << "\n";
    }
}
 
int main() {
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
