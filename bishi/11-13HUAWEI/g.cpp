#include <bits/stdc++.h>

using namespace std;

struct MagicCircle {
    int position;
    int energy;
};

int main() {
    int n, c;
    cin >> n >> c;
    c--;  // 转换为从0开始的索引

    vector<MagicCircle> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].position >> a[i].energy;
    }

    vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    int res = 1000000000;
    do {
        int cur = 0, pre = c;
        int t = 0;
        for (int x : p) {
            t += abs(a[x].position - a[pre].position);
            cur += t* a[x].energy;
            pre = x;
        }
        res = min(res, cur);
    } while (next_permutation(p.begin(), p.end()));
 
    cout << res << endl;
    return 0;
}