#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(3));

    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i] = {x, y, z};
    }

    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) return a[0] > b[0];
        if (a[1] != b[1]) return a[1] > b[1];
        return false;
    });

    int ans = 0;
    vector<int> f(n, 0);

    for (int i = 0; i < n; ++i) {
    	f[i] = arr[i][2];
        for (int j = 0; j < i; ++j) {
            if (arr[j][1] < arr[i][1] && arr[j][2] < arr[i][2] and arr[j][0] > arr[i][0]) {
                f[i] = max(f[i], f[j] + arr[i][2]);
            }
        }
        ans = max(ans, f[i]);
    }

    cout << ans << endl;

    return 0;
}