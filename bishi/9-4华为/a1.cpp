#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;
    vector<int> brr(m);
    for (int i = 0; i < m; i++) {
        cin >> brr[i];
    }

    unordered_map<int, int> ans;

    int base = 1;
    int i = 0;
    while (i < n) {
        int z = min(i + base, n);
        unordered_map<int, int> tmp;
        for (int j = i; j < z; j++) {
            tmp[arr[j]]++;
        }
        for (int j = i; j < z; j++) {
            if (j < m && tmp[brr[j]] > 0) {
                tmp[brr[j]]--;
            }
        }
        for (const auto& kv : tmp) {
            if (kv.second > 0) {
                ans[kv.first] += kv.second;
            }
        }
        i += base;
        base *= 2;
    }

    vector<pair<int, int>> arr_vec(ans.begin(), ans.end());
    sort(arr_vec.begin(), arr_vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second != b.second ? b.second < a.second : b.first < a.first;
    });

    for (const auto& p : arr_vec) {
        cout << p.first;
    }
    cout << endl;

    return 0;
}
