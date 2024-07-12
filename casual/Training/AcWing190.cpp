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
const int N = 9;
using std::string;
int n = 0;
string a[N], b[N], A, B;

int extend(std::queue<string> &q, std::unordered_map<string, int> &da, std::unordered_map<string, int> &db, string a[N], string b[N]) {
	int d = da[q.front()];
	while (q.size() && da[q.front()] == d) {
		auto t = q.front(); q.pop();

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < t.size(); ++j) 
				if (t.substr(j, a[i].size()) == a[i]) {
					string state = t.substr(0, j) + b[i] + t.substr(j + a[i].size());
					if (db.count(state)) return da[t] + 1 + db[state];
					if (da.count(state)) continue;
					da[state] = da[t] + 1;
					q.push(state);
				}
			
	}
	return 11;		
}


int bfs() {
	if (A == B) return 0;
	std::queue<string> qa, qb;
	std::unordered_map<string, int> da, db;
	qa.push(A), da[A] = 0;
	qb.push(B), db[B] = 0;

	int st = 0;

	while (qa.size() && qb.size()) {
		int t;
		if (qa.size() < qb.size()) t = extend(qa, da, db, a, b);
		else t = extend(qb, db, da, b, a);

		if (t <= 10) return t;
		if (++st == 10) return -1;
	}
	return -1;
}

void solve() {
	std::cin >> A >> B;
    while (std::cin >> a[n] >> b[n]) ++n;

    int ans = bfs();

    if (ans == -1) std::cout << "NO ANSWER!\n";
    else std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
