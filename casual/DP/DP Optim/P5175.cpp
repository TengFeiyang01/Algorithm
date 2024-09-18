#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

template<class T>
class Matrix {
public:
    static int  mod;
    std::vector<std::vector<T> > sorce;
    //默认构造n阶单位阵。
    Matrix(int n):sorce(n, std::vector<T>(n)) {
        for (int i = 0; i < n; i++) {
            sorce[i][i] = 1;
        }
    }

    Matrix(int n, int m):sorce(n, std::vector<T>(m)) {}
    //重载乘法运算符
    Matrix operator* (Matrix &b) {
        Matrix res(sorce.size(), b.sorce[0].size());
        for (int i = 0; i < sorce.size(); i++)
            for (int j = 0; j < b.sorce[0].size(); j++) {
                for (int k = 0; k < b.sorce.size(); k++) {
                    res.sorce[i][j] = (res.sorce[i][j] + sorce[i][k] * b.sorce[k][j]) % res.mod;
                }
            }
        return res;
    }
    void operator*=(Matrix& b) {
        *this = *this * b;
    }

    Matrix operator^(i64 n) {
        Matrix ans(sorce.size());
        Matrix temp = *this;
        while (n) {
            if (n & 1) ans *= temp;
            n >>= 1;
            temp *= temp;
        }
        return ans;
    }
    void operator^=(i64 n) {
        *this = *this ^ n;
    }
};
template<typename T> int Matrix<T>::mod = 1e9+7;

void solve() {
	i64 n, a1, a2, x, y;
	std::cin >> n >> a1 >> a2 >> x >> y;
	Matrix<i64> a(4, 4), b(4, 1);
	b.sorce = {
		{a1 * a1 % b.mod},
		{a2 * a2 % b.mod},
		{a1 * a1 % b.mod},
		{a1 * a2 % b.mod},
	};
	a.sorce = {
		{1, 1, 0, 0},
		{0, x * x % a.mod, y * y % a.mod, 2LL * x * y % a.mod},
		{0, 1, 0, 0},
		{0, x % a.mod, 0, y % a.mod}
	};
	if (n == 1) {
		std::cout << a1 * a1 % a.mod << "\n";
	} else {
		a ^= n - 1;
        a *= b;
		std::cout << a.sorce[0][0] << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
