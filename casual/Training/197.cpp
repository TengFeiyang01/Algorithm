#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

struct Prime {
    int n;
    std::vector<int> _primes;
    std::vector<int> _phi;
    std::vector<int> _spf;
    std::vector<int> _d;
    std::vector<int> _cnt;
    Prime() : n{0} {}
    Prime(int n) : Prime() {
        init(n);
        _d[1] = 1;
    }

    void init(int m) {
        _phi.resize(m + 1);
        _spf.resize(m + 1);
        _cnt.resize(m + 1);
        _d.resize(m + 1);

        for (int i = 2; i <= m; ++i) {
            if (!_spf[i]) {
                _spf[i] = i;
                _phi[i] = i - 1;
                _cnt[i] = 1;
                _d[i] = 2;
                _primes.emplace_back(i);
            } 

            for (auto p : _primes) {
                if (i * p > m) break;
                _spf[i * p] = p;
                if (i % p == 0) {
                    _cnt[i * p] = _cnt[i] + 1;
                    _d[i * p] = _d[i] / _cnt[i * p] * (_cnt[i * p] + 1);
                    _phi[i * p] = p * _phi[i];
                    break;
                } else {
                    _cnt[i * p] = 1;
                    _d[i * p] = _d[i] * 2;
                    _phi[i * p] = (p - 1) * _phi[i];
                }
            }
            n = m;
        }
    }
    
    int spf(int m) {
        if (m > n) init(2 * m);
        return _spf[m];
    }
    
    int phi(int m) {
        if (m > n) init(2 * m);
        return _phi[m];
    }
};

void solve() {
    int n;
    std::cin >> n;
    auto prime = Prime(1000010)._primes;
    for (int &p : prime) {
    	i64 cnt = 0, cur = p;
    	while (n / cur) {
    		cnt += n / cur;
    		cur *= p;
    	}
    	if (cnt) {
    		std::cout << p << " " << cnt << "\n";
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
