#include <bits/stdc++.h>

#define int long long // 记得开 long long
#define ull unsigned long long

const int N = 1e6 + 10;
const int M = 1e4 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

using namespace std;
int a[40], n, m, b[40];

bool esmite(int pos, int res) {
    return b[pos + 1] >= res;
}

int ans = INF;

int find(int x) { // STL熟练的可以使用 upper_bound 或者 lower_bound 本蒟蒻这两玩意用法分不清故手写
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] / 2 <= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void dfs(int num, int rest, int pos) { // num 当前切开了几个瓜，rest 还剩下需要多少瓜，pos当前搜到哪个位置了，防止往前搜
    if (rest == 0) { // 统计答案
        ans = min(ans, num);
        return;
    }
    if (!esmite(pos, rest))
        return; // 可行性剪枝
    for (int i = max(pos + 1, find(rest)); i <= n; i++) { // 当然这里也可以直接pos+1（说过了数据水）
        if (a[i] / 2 > rest)
            continue;
        dfs(num + 1, rest - a[i] / 2, i);
        if (a[i] > rest)
            continue;
        dfs(num, rest - a[i], i);
    }
}

signed main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> m;
    m *= 2; // 乘2小技巧
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a + 1, a + 1 + n, greater<int>()); // 排序
    for (int i = n; i > 0; i--) { // 后缀和
        b[i] = b[i + 1] + a[i];
    }
    dfs(0, m, 0);
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
    return 0;
}
