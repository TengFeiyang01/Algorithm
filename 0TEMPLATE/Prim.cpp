struct Prime {
    int n;
    std::vector<int> _primes;
    std::vector<int> _phi;
    std::vector<int> _spf;
    Prime() : n{0} {}
    Prime(int n) : Prime() {
        init(n);
    }

    void init(int m) {
        _phi.resize(m + 1);
        _spf.resize(m + 1);

        for (int i = 2; i <= m; ++i) {
            if (!_spf[i]) {
                _spf[i] = i;
                _phi[i] = i - 1;
                _primes.emplace_back(i);
            } 

            for (auto p : _primes) {
                if (i * p > m) break;
                _spf[i * p] = p;
                if (i % p == 0) {
                    _phi[i * p] = p * _phi[i];
                    break;
                } else {
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