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
    int n, b, k, x;
    std::cin >> n >> b >> k >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    Matrix<i64> base(x), ans(x);
    for (int i = 0; i < x; ++i) {
    	for (int j = 0; j < x; ++j) {
    		ans.sorce[i][j] = 0;
    		base.sorce[i][j] = 0;
    	}
    }
    ans.sorce[0][0] = 1;
    for (int i = 0; i < x; ++i) {
    	for (int j = 0; j < n; ++j) {
    		base.sorce[(i * 10 + a[j]) % x][i]++;
    	}
    }
    ans = (base ^ b) * ans;
    std::cout << ans.sorce[k][0];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
