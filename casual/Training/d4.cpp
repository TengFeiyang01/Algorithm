#include <iostream>

using namespace std;
int n;

double getsc(int u) {
    if (u < 60) return 0.0;
    else if (u < 64) return 1.0;
    else if (u < 68) return 1.5;
    else if (u < 72) return 2.0;
    else if (u < 75) return 2.3;
    else if (u < 78) return 2.7;
    else if (u < 82) return 3.0;
    else if (u < 85) return 3.3;
    else if (u < 90) return 3.7;
    else return 4.0;
}

int main() {
    cin >> n;
    double t = 0;
    int sc, t1 = 0;
    int W[12];
    for (int i = 0; i < n; ++i) {
        cin >> W[i];
        t1 += W[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> sc;
        t += getsc(sc) * W[i];
    }
    
    printf("%.2f", t / t1);
    
    return 0;
}