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
const int N = 9, M = 1 << N;

int mp[M], ones[M];
int row[N], col[N], cell[3][3];
char str[100];

void init() {
	for (int i = 0; i < N; ++i) row[i] = col[i] = (1 << N) - 1;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cell[i][j] = (1 << N) - 1;
}

void draw(int x, int y, int t, bool is_set) {
	if (is_set) str[x * N + y] = '1' + t;
	else str[x * N + y] = '.';

	int v = 1 << t;
	if (!is_set) v = -v;

    //如果某位没被放，则它的二进制位应该是1， 所以应该减去v
    //如果放了，它的二进制应该是0，则经过上面的取反，负负得正，-v实际上就是把二进制0变为1    
	row[x] -= v;
	col[y] -= v;
	cell[x / 3][y / 3] -= v;
}

int get(int x, int y) {
	return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
	if (!cnt) return true;

	//最多还能填的数子
	int minv = 10, x, y;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (str[i * N + j] == '.') {
				int state = get(i, j);
				if (ones[state] < minv) {
					minv = ones[state];
					x = i, y = j;
				}
			}
	int state = get(x, y);
	for (int i = state; i; i -= (i & -i)) {
		int t = mp[i & -i];
		draw(x, y, t, true);
		if (dfs(cnt - 1)) return true;
		draw(x, y, t, false);
	}
	return false;
}

void solve() {
   	init();
	int cnt = 0;
	for (int i = 0, k = 0; i < N; ++i)
		for (int j = 0; j < N; ++j, ++k)
			if (str[k] != '.') {
				int t = str[k] - '1';
				draw(i, j, t, true);
			} else cnt++;
	dfs(cnt);
	puts(str);
	//std::cout << str << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    for (int i = 0; i < N; ++i) mp[1 << i] = i;
    for (int i = 0; i < 1 << N; ++i)
    	for (int j = 0; j < N; ++j)
    		ones[i] += i >> j & 1;

    while (std::cin >> str, str[0] != 'e') {
	    solve();
    }

    return 0;
}
