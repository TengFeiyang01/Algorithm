#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 定义一个结构体来存储 (t, w) 对
struct Pair {
    int t, w;
    bool operator<(const Pair& other) const {
        return t < other.t;
    }
};

void solve() {
    int n;
    cin >> n;
    
    vector<Pair> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].t >> a[i].w;
    }

    // 对 (t, w) 对进行排序
    sort(a.begin(), a.end());

    int i = 0, ans = 0;
    int cur = a[0].t;
    
    // 使用优先队列作为最小堆，存储 (w, t) 对
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;

    while (i < n) {
        // 将所有 t <= cur 的 (w, t) 对入堆
        while (i < n && a[i].t <= cur) {
            h.push({a[i].w, a[i].t});
            ++i;
        }

        if (h.empty()) {
            cur = a[i].t;
            while (i < n && a[i].t <= cur) {
                h.push({a[i].w, a[i].t});
                ++i;
            }
        }

        if (i == n) {
            break;
        }

        // 处理堆中的数据
        while (!h.empty() && h.top().first + cur <= a[i].t) {
            cur += h.top().first;
            ans += cur - h.top().second;
            h.pop();
        }

        if (!h.empty() && h.top().first + cur > a[i].t) {
            pair<int, int> top = h.top();
            h.pop();
            h.push({top.first - (a[i].t - cur), top.second});
            cur = a[i].t;
        }
    }

    // 处理剩下的堆中的数据
    while (!h.empty()) {
        cur += h.top().first;
        ans += cur - h.top().second;
        h.pop();
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}