#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
vector<int> a;
map<int, vector<int>> g;
map<int, int> val, pos;

int dfs(int x) {
    int sum = val[x];
    for (int y : g[x]) {
        sum += dfs(y);
    }
    a[pos[x]] = sum;
    return sum;
}

int main() {
    cin >> n;
    a.resize(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    int i = 0, p = 0, q = 0;
    while (i < 2 * n) {
        if (a[i] == -1) {
            int j = i + 1;
            while (j < 2 * n && a[j] != -1) {
                pos[p] = j;
                val[p] = a[j];
                g[q].push_back(p);
                p++;
                j++;
            }
            q++;
            i = j;
        } else {
            val[p] = a[i];
            pos[p] = i;
            p++;
            i++;
        }
    }

    dfs(0);

    for (int i = 0; i < 2 * n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
