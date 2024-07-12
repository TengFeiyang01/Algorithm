#include <bits/stdc++.h>

// using i64 = long long;
// struct DSU {
//     std::vector<int> f, siz;
    
//     DSU() {}
//     DSU(int n) {
//         init(n);
//     }
    
//     void init(int n) {
//         f.resize(n);
//         std::iota(f.begin(), f.end(), 0);
//         siz.assign(n, 1);
//     }
    
//     int find(int x) {
//         while (x != f[x]) {
//             x = f[x] = f[f[x]];
//         }
//         return x;
//     }
    
//     bool same(int x, int y) {
//         return find(x) == find(y);
//     }
    
//     bool merge(int x, int y) {
//         x = find(x);
//         y = find(y);
//         if (x == y) {
//             return false;
//         }
//         siz[x] += siz[y];
//         f[y] = x;
//         return true;
//     }
    
//     int size(int x) {
//         return siz[find(x)];
//     }
// };
// void solve() {
//     int n;
//     std::cin >> n;
    
//     std::vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         std::cin >> a[i];
//         a[i]--;
//     }
    
//     int min = 0, max = 0;
//     bool chain = false;
//     DSU dsu(n);
//     for (int i = 0; i < n; i++) {
//         dsu.merge(i, a[i]);
//     }
//     std::vector<int> e(n);
//     for (int i = 0; i < n; i++) {
//         if (a[a[i]] == i) {
//             e[dsu.find(i)] = 1;
//             chain = true;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (dsu.find(i) == i) {
//             if (!e[i]) {
//                 min++;
//             }
//             max++;
//         }
//     }
//     min += chain;
//     std::cout << min << " " << max << "\n";
// }

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), time(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
    }

    int clock = 1;

    int twos = 0, mores = 0;
    for (int i = 0; i < n; ++i) {
        if (!time[i]) {
            int start_time = clock;
            int j = i;
            while (!time[j]) {
                time[j] = clock;
                clock += 1;
                j = a[j];
            }
            if (time[j] < start_time) {
                continue;
            }
            if (clock - time[j] == 2) {
                twos += 1;
            } else {
                mores += 1;
            }
        }
    }
    std::cout << mores + (twos > 0) << " " << mores + twos << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}