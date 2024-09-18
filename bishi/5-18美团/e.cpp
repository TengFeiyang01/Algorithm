#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 200005;
const ll mod = 1e9 + 7;

ll st[MAX_N][26];
pair<double, int> p[26];
vector<string> a(MAX_N);

// Fast modular exponentiation
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;

    // Initialize p with high values for comparison
    for (int i = 0; i < 26; i++) {
        p[i] = {1000000.0, 0};
    }

    // Read all strings and preprocess
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (char ch : a[i]) {
            st[i][ch - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (st[i][j] == 0) continue;
            if ((2 * (int)a[i].size() - st[i][j]) * 1.0 / st[i][j] < p[j].first) {
                p[j].first = (2 * (int)a[i].size() - st[i][j]) * 1.0 / st[i][j];
                p[j].second = i;
            }
        }
    }

    cin >> q;
    string s;
    // Process each query
    while (q--) {
        cin >> s;
        ll res = 0;
        for (char ch : s) {
            int cnt = ch - 'a';
            int c = p[cnt].second;
            if (c == 0) {
                res = -1;
                break;
            }
            res = (res + (2 * (int)a[c].size() - st[c][cnt]) * qpow(st[c][cnt], mod - 2)) % mod;
        }
        cout << res << "\n";
    }

    return 0;
}
