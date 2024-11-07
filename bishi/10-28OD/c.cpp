#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 可行性检查函数
bool check(const vector<int>& x, int M, int D) {
    int n = x.size();
    int count = 0;
    int i = 0;

    while (i < n) {
        int s = x[i] + D;

        int j = i;
        while (j < n && x[j] <= s) {
            j++;
        }
        j--; 

        int bus_stop = x[j];

        count++;

        if (count > M) {
            return false;
        }

        int next_cover = bus_stop + D;

        i = j + 1;
        while (i < n && x[i] <= next_cover) {
            i++;
        }
    }

    return true;
}

int minMaxDistance(vector<int>& x, int M) {
    sort(x.begin(), x.end()); 

    int left = 0;
    int right = x.back() - x.front(); 

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (check(x, M, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    int result = minMaxDistance(x, M);
    cout << result << endl;

    return 0;
}
