#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using namespace std;

using i64 = long long;
struct P {
    i64 x, y;
    bool operator <(const P& B)const { return x < B.x; }
}p[100050];
i64 dis(P &A, P &B) { return i64(A.x-B.x)*(A.x-B.x) + i64(A.y-B.y)*(A.y-B.y); }
P Q[100050];

i64 Divide(int l, int r) {
    if(l == r) return 1e18;
    i64 mid = (l+r)>>1, d, tx = p[mid].x, tot = 0;
    d = min(Divide(l, mid), Divide(mid+1, r));
    for(int i = l, j = mid+1; (i <= mid || j <= r); i++) {
        while(j <= r && (p[i].y > p[j].y || i > mid)) Q[tot++] = p[j], j++; 
        if(abs(p[i].x - tx) < d && i <= mid) {
            for(int k = j-1; k > mid && j-k < 3; k--) d = min(d, dis(p[i], p[k]));
            for(int k = j; k <= r && k-j < 2; k++) d = min(d, dis(p[i], p[k]));
        }
        if(i <= mid) Q[tot++] = p[i];
    }
    for(int i = l, j = 0; i <= r; i++, j++) p[i] = Q[j];
    return d;
}

i64 closestSquaredDistance(vector<int> x, vector<int> y) {
	int n = x.size();
	for(int i = 1; i <= n; i++) {
		p[i].x = x[i - 1];
		p[i].y = y[i - 1];
	}
    sort(p+1, p+1+n);
    return Divide(1, n);
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
    	cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
    	cin >> y[i];
    }
    cout << closestSquaredDistance(x, y) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
