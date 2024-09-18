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
using std::string;
using PIS = std::pair<int, string>;
const int N = 1e5 + 13;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int f(string state) {
    int res = 0;
    for (int i = 0; i < state.size(); ++i)
        if (state[i] != 'x') {
            int t = state[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    return res;
}


string bfs(string start) {
	string ed = "12345678x";
    char op[4] = {'u', 'r', 'd', 'l'};

	std::unordered_map<string, int> dist;
	std::unordered_map<string, std::pair<string, char>> prev;
	std::priority_queue<PIS, std::vector<PIS>, std::greater<PIS>> pq;

	dist[start] = 0;
	pq.emplace(f(start), start);

	while (pq.size()) {
		auto t = pq.top(); pq.pop();
		int x, y;
		string state = t.second;
		if (state == ed) break;
		//从堆中取出的估计距离 + 真实距离
		int d = dist[state];
        for (int i = 0; i < state.size(); i ++ )
            if (state[i] == 'x') {
                x = i / 3, y = i % 3;
                break;
            }
		string sc = state;
		for (int i = 0; i < 4; ++i) {
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && b >= 0 && a < 3 && b < 3) {
    			std::swap(state[x * 3 + y], state[a * 3 + b]);
    			if (!dist.count(state) || dist[state] > d + 1) {
    				dist[state] = d + 1;
    				prev[state] = {sc, op[i]};
    				pq.emplace(dist[state] + f(state), state);
    			}
    			std::swap(state[x * 3 + y], state[a * 3 + b]);  
			}
		}				
	}
	string res;
	while (ed != start) {
		res += prev[ed].second;
		ed = prev[ed].first;
	}
	std::reverse(all(res));
	return res;
}

void solve() {
    string start, c, step;
    while (std::cin >> c) {
    	start += c;
    	if (c != "x") step += c;
    }
    int cnt = 0;
    for (int i = 0; i < step.size(); ++i)
    	for (int j = i + 1; j < step.size(); ++j)
    		if (step[i] > step[j])
    			cnt++;
    if (cnt & 1) std::cout << "unsolvable";
    else std::cout << bfs(start) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}