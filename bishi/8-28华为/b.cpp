#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int interval;
    cin >> interval;

    if (interval == 0) {
        int mz = 0;
        map<int, int> hp;
        for (int v: arr) {
            hp[v]++;
            mz = max(mz, hp[v]);
        }

        int res = -1;
        for (int i = 0; i < n; i++) {
            if (hp[arr[i]] == mz) {
                if (res == -1 || res > arr[i]) {
                    res = arr[i];
                }
                break;
            }
        }
        cout << res << '\n';
    } else {
        int mz = 0;
        map<int, multiset<int>> hp;
        for (int i = 0; i < n; i++) {
            hp[arr[i] % interval].insert(arr[i]);
            mz = max((int)hp[arr[i] % interval].size(), mz);
        }
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (hp[arr[i] % interval].size() == mz) {
                if (res == -1 || res > arr[i]) {
                    res = arr[i];
                }
            }
        }
        cout << res << '\n';
    }



    return 0;
}