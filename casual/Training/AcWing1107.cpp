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
using std::string;
const int N = 1e5 + 13;
//A 12345678 87654321
//B 12345678 41236785
//C 12345678 17245368

string A(string a) {
    auto b = a;
    std::reverse(all(b));
    return b;
}

string B(string a) {
    auto b = a;
    b[0] = a[3];
    b[1] = a[0];
    b[2] = a[1];
    b[3] = a[2];
    b[4] = a[5];
    b[5] = a[6];
    b[6] = a[7];
    b[7] = a[4];
    return b;
}

string C(string a) {
    auto b = a;
    b[1] = a[6];
    b[2] = a[1];
    b[5] = a[2];
    b[6] = a[5];
    return b;
}

void solve() {
    int x;
    string start = "", ed;
    for (int i = 0; i < 8; ++i) {
    	std::cin >> x;
    	ed += char('0' + x);
    	start += char(i + '1');
    }
    std::unordered_map<string, int> dist;
    std::unordered_map<string, std::pair<char, string>> pre;
    std::queue<string> q;


    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        string t = q.front(); q.pop();
        if (t == ed) break;
        string ne[3];
        ne[0] = A(t);
        ne[1] = B(t);
        ne[2] = C(t);
        for (int i = 0; i < 3; ++i) {
            if (!dist.count(ne[i])) {
                dist[ne[i]] = dist[t] + 1;
                pre[ne[i]] = {char('A' + i), t};
                q.push(ne[i]);
            }
        }
    }

    std::cout << dist[ed] << "\n";
    std::string res;
    while (ed != start) {
        res += pre[ed].first; 
        ed = pre[ed].second;
    }
    std::reverse(all(res));
    if (sz(res)) std::cout << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
