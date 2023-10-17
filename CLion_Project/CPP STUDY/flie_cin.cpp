#include <bitsdc++.h>


#define endl '\n'
#define ll long long
#define N 1000005

ll n, m, k;
int r[N], c[N], lr[N], lc[N];
ll cnt1, cnt2;
string s1[N], s2[N];
int x[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    string a, b;
    int j;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= k; i++) {
            cin >> s1[i] >> x[i] >> s2[i];
        }
        ll ans = 0;
        for (int i = k; i >= 1; i--) {
            a = s1[i], b = s2[i], j = x[i];
            if (a == "row") {
                if (b == "on") {
                    if (r[j] || lr[j])continue;
                    r[j] = 1;
                    ans += m - cnt2;
                } else {
                    if (r[j] || lr[j])continue;
                    lr[j] = 1;
                }
                cnt1++;
            } else {
                if (b == "on") {
                    if (c[j] || lc[j])continue;
                    c[j] = 1;
                    ans += n - cnt1;
                } else {
                    if (c[j] || lc[j])continue;
                    lc[j] = 1;
                }
                cnt2++;
            }
        }
        cout << ans;
    }
    return 0;
}