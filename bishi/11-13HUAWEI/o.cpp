#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    int res = 1, p = N - 1;
    for (int i = N - 2; i >= 0; --i) 
    {
        if (a[i] + p >= a[N - 1]) {
            res++;
        }
    }
    cout << res << "\n";

    return 0;
}