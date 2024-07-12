#include <bits/stdc++.h>

class Product {
public:
    std::string name;
    int cnt, id;

    bool operator<(const Product& other) const {
        if (cnt != other.cnt) {
            return cnt > other.cnt;
        }
        return id < other.id;
    }
};

int main() {
    int n, q;
    std::cin >> n >> q;

    std::set<std::string> st;
    for (int i = 0; i < q; ++i) {
        std::string s;
        std::cin >> s;
        st.insert(s);
    }

    std::vector<Product> a(n);

    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> a[i].name >> m;
        a[i].id = i;

        for (int j = 0; j < m; ++j) {
            std::string s;
            std::cin >> s;
            if (st.count(s)) {
                a[i].cnt++;
            }
        }
    }

    // 排序商品
    std::sort(a.begin(), a.end());

    // 输出商品名
    for (const auto& product : a) {
        std::cout << product.name << std::endl;
    }

    return 0;
}
