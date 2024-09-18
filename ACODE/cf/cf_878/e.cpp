#include <bits/stdc++.h>

void solve() {
	int n, Q, t;
    std::string s[2];
    std::cin >> s[0] >> s[1];
    int cnt = 0;
    for (int i = 0; i < s[0].size(); ++i) {
    	cnt += s[0][i] != s[1][i];
    }
    std::cin >> t >> Q;
    
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < Q; ++i) {
    	int op;
    	std::cin >> op;
        if (q.size() and q.front().first <= i - t) {
            int p = q.front().second;
            if (s[0][p] != s[1][p]) cnt++;
            q.pop();
        }
    	if (op == 1) {
    		int pos; std::cin >> pos;
            pos--;
            if (s[0][pos] != s[1][pos]) cnt--;
    		q.push({i, pos});
    	} else if (op == 2) {
    		int id1, id2, p1, p2;
    		std::cin >> id1 >> p1 >> id2 >> p2;
            id1--, id2--, p1--, p2--;
            if (id1 != id2) {
                cnt -= s[id1][p1] != s[id2][p1];
                cnt -= s[id1][p2] != s[id2][p2];
                std::swap(s[id1][p1], s[id2][p2]);
                cnt += s[id1][p1] != s[id2][p1];
                cnt += s[id1][p2] != s[id2][p2];
            } else {
                cnt -= s[id1][p1] != s[id1 ^ 1][p1];
                cnt -= s[id1][p2] != s[id1 ^ 1][p2];
                std::swap(s[id1][p1], s[id2][p2]);
                cnt += s[id1][p1] != s[id1 ^ 1][p1];
                cnt += s[id1][p2] != s[id1 ^ 1][p2];
            }
    	} else {
    		std::cout << (cnt > 0 ? "NO\n" : "YES\n");
    	}
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
