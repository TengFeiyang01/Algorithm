#include <bits/stdc++.h>
using namespace std;

const double INF = 1e18;

double L2(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    long long x, y;
    scanf("%lld %lld", &x, &y);

    vector<array<double, 3>> a(n);
    for (long long i = 0; i < n; ++i) {
        double xi, yi;
        long long z;
        scanf("%lf %lf %lld", &xi, &yi, &z);
        a[i] = {xi, yi, (double)z};
    }

    sort(a.begin(), a.end(), [](auto lhs, auto rhs) {
        return lhs[2] < rhs[2];
    });

    vector<double> d0(n), d1(n - 1);
    for (long long i = 0; i < n; ++i) {
        d0[i] = L2(x, y, a[i][0], a[i][1]);
    }

    for (long long i = 0; i < n - 1; ++i) {
        d1[i] = L2(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
    }

    vector<vector<double>> f(n, vector<double>(k, INF));
    f[0][k - 1] = d0[0];

    for (long long i = 1; i < n; ++i) {
        double min_prev = INF;
        for (long long j = 0; j < k; ++j) {
            min_prev = min(min_prev, f[i - 1][j]);
        }
        f[i][k - 1] = min_prev + d0[i] + d0[i - 1];
        
        for (long long j = 0; j < k - 1; ++j) {
            f[i][j] = f[i - 1][j + 1] + d1[i - 1];
        }
    }

    double result = INF;
    for (long long j = 0; j < k; ++j) {
        result = min(result, f[n - 1][j]);
    }
    
    result += d0.back();

    printf("%.1f\n", round(result * 10) / 10);
    return 0;
}
