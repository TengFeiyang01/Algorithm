#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int HA, WA;
    std::cin >> HA >> WA;
    
    std::vector<std::string> A(HA);
    for (int i = 0; i < HA; i++) {
        std::cin >> A[i];
    }
    
    int HB, WB;
    std::cin >> HB >> WB;
    
    std::vector<std::string> B(HB);
    for (int i = 0; i < HB; i++) {
        std::cin >> B[i];
    }
    
    int HX, WX;
    std::cin >> HX >> WX;
    
    std::vector<std::string> X(HX);
    for (int i = 0; i < HX; i++) {
        std::cin >> X[i];
    }
    
    for (int ia = -10; ia <= 10; ia++) {
        for (int ja = -10; ja <= 10; ja++) {
            for (int ib = -10; ib <= 10; ib++) {
                for (int jb = -10; jb <= 10; jb++) {
                    bool ok = true;
                    std::vector c(HX, std::string(WX, '.'));
                    for (int i = 0; i < HA; i++) {
                        for (int j = 0; j < WA; j++) {
                            int x = i + ia;
                            int y = j + ja;
                            if (A[i][j] == '#') {
                                if (x < 0 || x >= HX || y < 0 || y >= WX) {
                                    ok = false;
                                    continue;
                                }
                                c[x][y] = '#';
                            }
                        }
                    }
                    for (int i = 0; i < HB; i++) {
                        for (int j = 0; j < WB; j++) {
                            int x = i + ib;
                            int y = j + jb;
                            if (B[i][j] == '#') {
                                if (x < 0 || x >= HX || y < 0 || y >= WX) {
                                    ok = false;
                                    continue;
                                }
                                c[x][y] = '#';
                            }
                        }
                    }
                    if (ok && c == X) {
                        std::cout << "Yes\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    std::cout << "No\n";
    return 0;
}
