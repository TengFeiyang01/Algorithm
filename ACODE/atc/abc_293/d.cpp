#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>());
	vector<int> deg(n);
	for (int i = 0; i < m; i++) {
		int a, c;
		char b, d;
		cin >> a >> b >> c >> d;
		a--; c--;
		graph[a].push_back(c);
		graph[c].push_back(a);
		deg[a]++; deg[c]++;
	}
	int x = 0, y = 0;
	vector<bool> used(n);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			queue<int> que;
			used[i] = true;
			que.push(i);
			bool f = true;
			while (!que.empty()) {
				int q = que.front(); que.pop();
				if (deg[q] != 2) f = false;
				for (int v : graph[q]) {
					if (!used[v]) {
						que.push(v);
						used[v] = true;
					}
				}
			}
			if (f) x++;
			else y++;
		}
	}
	cout << x << ' ' << y << '\n';
}