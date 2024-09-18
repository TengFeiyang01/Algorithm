#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

template<class T>
class Matrix {
public:
    static int  mod;
    std::vector<std::vector<T> > sorce;
    //默认构造n阶单位阵。
    Matrix(int n):sorce(n + 1, std::vector<T>(n + 1)) {
        for (int i = 1; i <= n; i++) {
            sorce[i][i] = 1;
        }
    }

    Matrix(int n, int m):sorce(n + 1, std::vector<T>(m + 1)) {}
    //重载乘法运算符
    Matrix operator* (Matrix b) {
        Matrix res(sorce.size() - 1, b.sorce[1].size() - 1);
        for (int i = 1; i <= sorce.size() - 1; i++)
            for (int j = 1; j <= b.sorce[1].size() - 1; j++) {
                res.sorce[i][j] = 0;
                for (int k = 1; k <= b.sorce.size() - 1; k++) {
                    res.sorce[i][j] += sorce[i][k] * b.sorce[k][j] % res.mod;
                }
                res.sorce[i][j] %= res.mod;
            }
        return res;
    }
    void operator*=(Matrix& b) {
        *this = *this * b;
    }

    Matrix operator^(i64 n) {
        Matrix ans(sorce.size() - 1);
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

    friend std::ostream& operator <<(std::ostream& cout, Matrix& a) {
        for (int i = 1; i <= a.sorce.size() - 1; i++) {
            for (int j = 1; j <= a.sorce[i].size() - 1; j++) {
                cout << a.sorce[i][j] << ' ';
            }
            cout << '\n';
        }
        return cout;
    }
    friend std::ostream& operator <<(std::ostream& cout, Matrix&& a) {
        for (int i = 1; i <= a.sorce.size() - 1; i++) {
            for (int j = 1; j <= a.sorce[i].size() - 1; j++) {
                cout << a.sorce[i][j] << ' ';
            }
            cout << '\n';
        }
        return cout;
    }

};
template<typename T> int Matrix<T>::mod = 1e9+7;


void solve() {
	int n;
    i64 k;
	std::cin >> n >> k;
	Matrix<i64> A(n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			std::cin >> A.sorce[i][j];
		}
	}
	A ^= k;
	std::cout << A;
}

int main() {
    std::ios ::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();

    return 0;
}
