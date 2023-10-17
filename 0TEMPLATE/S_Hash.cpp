class Hash {
using ull = unsigned long long;
public:
    Hash(std::string s) {
        int n = s.size();
        p.resize(n + 1, 1);
        h.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + s[i - 1];         
        }
    }

    ull get(int l, int r) {
        return h[r + 1] - h[l] * p[r - l + 1];
    }

    bool euqal(int l1, int r1, int l2, int r2) {
        return get(l1, r1) == get(l2, r2);
    }

private:
    static const int P = 13331;
    std::vector<ull> p, h;
};