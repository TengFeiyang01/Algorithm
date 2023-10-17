#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(k, -1);
    function<int(int)> fp = [&](int u) {
        return p[u] < 0 ? u : p[u] = fp(p[u]);
    };
    vector<int> cur_x(k), cur_y(k);
    map<string, int> mp;
    vector<string> s(k);
    vector color(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i < k; i += 1) {
        cin >> s[i] >> cur_x[i] >> cur_y[i];
        if (color[cur_x[i]][cur_y[i]] == -1 or
            s[i] > s[color[cur_x[i]][cur_y[i]]]) {
            if (color[cur_x[i]][cur_y[i]] != -1) {
                p[color[cur_x[i]][cur_y[i]]] = i;
            }
            color[cur_x[i]][cur_y[i]] = i;
        } else {
            p[i] = color[cur_x[i]][cur_y[i]];
        }
        mp[s[i]] = i;
    }
    int q;
    cin >> q;
    for (int qi = 0; qi < q; qi += 1) {
        string si;
        char d;
        cin >> si >> d;
        if (not mp.count(si)) {
            cout << "unexisted empire.\n";
            continue;
        }
        int i = mp[si];
        if (p[i] >= 0) {
            cout << "unexisted empire.\n";
            continue;
        }
        int nxt_x = cur_x[i], nxt_y = cur_y[i];
        if (d == 'W') {
            nxt_x -= 1;
        }
        if (d == 'S') {
            nxt_x += 1;
        }
        if (d == 'A') {
            nxt_y -= 1;
        }
        if (d == 'D') {
            nxt_y += 1;
        }
        if (nxt_x < 1 or nxt_x > n or nxt_y < 1 or nxt_y > m) {
            cout << "out of bounds!\n";
            continue;
        }
        if (color[nxt_x][nxt_y] == -1) {
            cout << "vanquish!\n";
            cur_x[i] = nxt_x;
            cur_y[i] = nxt_y;
            color[nxt_x][nxt_y] = i;
            p[i] -= 1;
            continue;
        }
        int j = fp(color[nxt_x][nxt_y]);
        if (j == i) {
            cout << "peaceful.\n";
            cur_x[i] = nxt_x;
            cur_y[i] = nxt_y;
            continue;
        }
        if (p[i] < p[j] or (p[i] == p[j] and s[i] > s[j])) {
            cout << s[i] << " wins!\n";
            cur_x[i] = nxt_x;
            cur_y[i] = nxt_y;
            p[i] += p[j];
            p[j] = i;
            continue;
        }
        cout << s[j] << " wins!\n";
        p[j] += p[i];
        p[i] = j;
    }
}