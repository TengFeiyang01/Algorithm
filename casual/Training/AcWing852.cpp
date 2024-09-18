#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 2010, M = 1e4 + 10;





int main() {
	int n, m;
	int dist[N], vis[N];
	int cnt[N];
    scanf("%d%d", &n, &m);
    int t = N;
	std::vector<std::vector<std::pair<int, int>>> adj(N);

	auto spfa = [&]() {
	    queue<int> q;

	    //判断负环， 而非是判断从 1 开始的负环
	    for (int i = 1; i <= n; i ++ ) {
	        vis[i] = true;
	        q.push(i);
	    }

	    while (q.size()) {
	        auto t = q.front();
	        q.pop();

	        vis[t] = false;

	        for (auto[j, w] : adj[t]) {
	            if (dist[j] > dist[t] + w) {
	                dist[j] = dist[t] + w;
	                cnt[j] = cnt[t] + 1;

	                if (cnt[j] >= n) return true;
	                if (!vis[j]) {
	                    q.push(j);
	                    vis[j] = true;
	                }
	            }
	        }
	    }
	    return false;
	};


    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].emplace_back(b, c);
    }

    if (spfa()) puts("Yes");
    else puts("No");
    return 0;
}