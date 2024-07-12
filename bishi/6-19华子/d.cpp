#include <iostream>
using namespace std;
const int N = 1010;
int diff[N][N]{0};

void insert(int x1, int y1, int x2, int y2, int c) {
    diff[x1][y1] += c;
    diff[x1][y2 + 1] -= c;
    diff[x2 + 1][y1] -= c;
    diff[x2 + 1][y2 + 1] += c;
}

int main() {
	std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, q;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
    	int x, y, c;
    	std::cin >> x >> y >> c;
    	x += 1000;
    	y += 1000;
    	insert(x - c, y - c, x + c, y + c, 1);
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    std::cin >> q;
    for (int i = 0; i < q; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	x += 1000;
    	y += 1000;
    	std::cout << diff[x][y] << "\n";
    }
            
    return 0;
}