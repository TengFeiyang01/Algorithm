#include <bits/stdc++.h>

using namespace std;

struct T {
    int s, e;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    auto comp = [](const T &a, const T &b) {
        if (a.s != b.s) return a.s > b.s;
        return a.e > b.e;  
    };
    priority_queue<T, vector<T>, function<bool(T,T)>> pq(comp);  

    for (int i = 0; i < n; i++) {
        T t;
        cin >> t.s >> t.e;
        pq.push(t);
    }
    
    int res = 0;
    int now = 1;
    while (!pq.empty()) {
        T cur = pq.top();
        if (now < cur.s) {
            now = cur.s;
        } else {
            while (!pq.empty() && pq.top().e < now) {
                pq.pop();
            }

            int sk = 0;
            while (sk < k && !pq.empty() && pq.top().s <= now) {
                res++;
                sk++;
                pq.pop();
            }
            now++;
        }
        
    }
    cout << res << '\n';

    return 0;
}