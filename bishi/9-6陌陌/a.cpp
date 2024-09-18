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
    Matrix operator* (Matrix b) {
        Matrix res(sorce.size(), b.sorce[0].size());
        for (int i = 0; i < sorce.size(); i++)
            for (int j = 0; j < b.sorce[0].size(); j++) {
                res.sorce[i][j] = 0;
                for (int k = 0; k < b.sorce.size(); k++) {
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
	int n, k;
	std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int &x : a) {
    	std::cin >> x;
    }
    for (int &x : b) {
    	std::cin >> x;
    }
    Matrix<i64> mat(n);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		if (j == b[i] - 1) {
    			mat.sorce[i][j] = 1;
    		} else {
    			mat.sorce[i][j] = 0;
    		}
    	}
    }
    mat ^= k;
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		ans[i] += mat.sorce[i][j] * a[j];
    		std::cout << mat.sorce[i][j] << " \n"[j == n - 1];
    	}
    }

    for (int i = 0; i < n; ++i) {
    	std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
