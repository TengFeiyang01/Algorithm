#include <bits/stdc++.h>
using ll = long long;
const int N = 1E3 + 5 , M = 2E4 + 5;
const ll INF = 1E18;
 
ll dis[N][M][2];
 
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n,m;
	std::cin >> n >> m;
	
	std::vector<int> edge(m + 1);
	std::vector<std::vector<std::array<int,3>> > g(n);
	
	for(int i = 1 ; i <= m ; ++i) {
		int u,v,w;
		std::cin >> u >> v >> w;
		--u ; --v;
		g[u].push_back({v , w , i});
		g[v].push_back({u , w , i}); 
		edge[i] = w;
	}
	
	using T = std::array<ll , 4>;
	std::priority_queue<T,std::vector<T>,std::greater<T> > q;
	
	memset(dis , 0x3f , sizeof dis);
	std::vector<ll> ans(n , -1);
	
	dis[0][0][0] = 0;
	q.push({0 , 0 , 0 , 0});
	
	while(!q.empty()) {
		
		auto f = q.top() ; q.pop();
		ll d = f[0] , u = f[1] , i = f[2] , modi = f[3];
		
		if ( dis[u][i][modi] < d ) {
			continue;
		}
		
		if (ans[u] == -1 || ans[u] > d) {
			ans[u] = d;
		}
			
		for(auto t : g[u]) {
			
			int v = t[0] , w = t[1] , j = t[2];
			
			if(i != 0 && modi == 0) {
				if (w > edge[i] && w % edge[i] == 0)  {
					ll nw = (1ll * w / edge[i] - 1) * edge[i];
					if(dis[v][j][1] > dis[u][i][0] + nw) {
						dis[v][j][1] = dis[u][i][0] + nw;
						q.push({dis[v][j][1] , v , j  , 1});
					}
				}	
			}
			
			if(dis[v][j][0] > dis[u][i][modi] + w) {
				dis[v][j][0] = dis[u][i][modi] + w;
				q.push({dis[v][j][0] , v , j , 0});
			}
			
		}
		
	}
	
	for(int i = 0 ; i < n ; ++i) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}
	
	return 0;
}