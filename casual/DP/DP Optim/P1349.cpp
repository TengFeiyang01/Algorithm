#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

template<class T>
class Matrix {
public:
    T  mod;
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
        res.mod = mod;
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
        ans.mod = mod;
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

void solve() {
    i64 p, q, a1, a2, n, m;
    std::cin >> p >> q >> a1 >> a2 >> n >> m;
    Matrix<i64> a(2);
    a.mod = m;
    a.sorce = {{p % m, q % m}, {1, 0}};
    if (n == 1) {
        std::cout << a1 << "\n";
    } else if (n == 2) {
        std::cout << a2 << "\n";
    } else {
        a ^= n - 2;
        std::cout << (a2 * a.sorce[0][0] % m + a1 * a.sorce[0][1] % m) % m << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
