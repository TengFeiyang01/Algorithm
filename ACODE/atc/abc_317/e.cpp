#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

constexpr int dx[] = {0, 0, -1, 1};
constexpr int dy[] = {-1, 1, 0, 0};

void solve() {
    int H, W;
    std::cin >> H >> W;
    std::vector<std::string> A(H);
    for (int i = 0; i < H; ++i) {
    	std::cin >> A[i];
    }

    std::vector passable(H, std::vector<bool>(W, true));
    int s = -1, g = -1;
    for (int i = 0; i < H; ++i) {
    	for (int j = 0; j < W; ++j) {
    		if (A[i][j] == '#') {
    			passable[i][j] = false;
    		} else if (A[i][j] == 'S') {
    			s = i * W + j;
    		} else if (A[i][j] == 'G') {
    			g = i * W + j;
    		} else if (A[i][j] == '^') {
    			int x = i - 1;
    			while (x >= 0 and (A[i][j] == '.' or A[i][j] == 'S' or A[i][j] == 'G')) {
    				passable[x][j] = false;
    				--x;
    			}
    		} else if (A[i][j] == 'v') {
                int x = i + 1;
                passable[i][j] = false;
                while (x < H && (A[x][j] == '.' || A[x][j] == 'S' || A[x][j] == 'G')) {
                    passable[x][j] = false;
                    x++;
                }
    		} else if (A[i][j] == '<') {
                int x = j - 1;
                passable[i][j] = false;
                while (x >= 0 && (A[i][x] == '.' || A[i][x] == 'S' || A[i][x] == 'G')) {
                    passable[i][x] = false;
                    x--;
                }
    		} else if (A[i][j] == '>') {
                int x = j + 1;
                passable[i][j] = false;
                while (x < W && (A[i][x] == '.' || A[i][x] == 'S' || A[i][x] == 'G')) {
                    passable[i][x] = false;
                    x++;
                }
            }
    	}
    }

   	std::queue<int> q;
   	q.push(s);
   	std::vector<int> dis(H * W, -1);
   	dis[s] = 0;

   	while (!q.empty()) {
   		int s = q.front();
   		q.pop();

   		int x = s / W, y = s % W;
   		for (int k = 0; k < 4; ++k) {
   			int nx = x + dx[k], ny = y + dy[k];
   			if (0 <= nx and nx < H and 0 <= ny and ny < W and passable[nx][ny]) {
   				int v = nx * W + ny;
   				if (dis[v] == -1) {
   					dis[v] = dis[s] + 1;
   					q.push(v);
   				}
   			}
   		}
   	}
   	std::cout << dis[g] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}