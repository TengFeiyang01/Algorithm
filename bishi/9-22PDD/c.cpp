#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using namespace std;


int solution(vector<vector<int>> matrix, int frameSize) {
	int mx = 0, n = matrix.size(), m = matrix[0].size();
	if (frameSize == 1) {
		for (int i = 0; i <= n - frameSize; ++i) {
			for (int j = 0; j <= m - frameSize; ++j) {
				mx = std::max(mx, matrix[i][j]);
			}
		}
		return mx;
	}
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i <= n - frameSize; ++i) {
		for (int j = 0; j <= m - frameSize; ++j) {
			int cur = 0;
			for (int p = 0; p < frameSize - 1; ++p) {
				cur += matrix[i][j + p];
			}
			for (int p = 0; p < frameSize - 1; ++p) {
				cur += matrix[i + p][j + frameSize - 1];
			}
			for (int p = 0; p < frameSize - 1; ++p) {
				cur += matrix[i + frameSize - 1][j + frameSize - 1 - p];
			}
			for (int p = 0; p < frameSize - 1; ++p) {
				cur += matrix[i + frameSize - 1 - p][j];
			}
			
			a[i][j] = cur;
			if (cur > mx) {
				mx = cur;
			}
		}
	}
	std::set<int> st;
	for (int i = 0; i <= n - frameSize; ++i) {
		for (int j = 0; j <= m - frameSize; ++j) {
			if (a[i][j] != mx) continue;
			for (int p = 0; p < frameSize - 1; ++p) {
				st.insert(matrix[i][j + p]);
			}
			for (int p = 0; p < frameSize - 1; ++p) {
				st.insert(matrix[i + p][j + frameSize - 1]);
			}
			for (int p = 0; p < frameSize - 1; ++p) {
				st.insert(matrix[i + frameSize - 1][j + frameSize - 1 - p]);
			}
			for (int p = 0; p < frameSize - 1; ++p) {
				st.insert(matrix[i + frameSize - 1 - p][j]);
			}
		}
	}
	int ans = 0;
	for (auto x : st) {
		ans += x;
	}
	return ans;
}

void solve() {
    std::cout << solution({{9,7,8,9,2},
						   {6,9,9,6,1},
							{4,10,1,3,10},
							{18,2,3,9,3},
							{4,6,8,5,21}}, 3);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
