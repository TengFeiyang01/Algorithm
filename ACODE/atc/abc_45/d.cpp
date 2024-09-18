#include<bits/stdc++.h>
#define int long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Equ(a,b) (fabs((a)-(b))<eps)
#define More(a,b) (((a)-(b))>(eps))
#define x first
#define y second
using namespace std;
const int N=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;
typedef pair<int, int> pii;
map <pii, int> cnt;
int h, w, n;
int ans[10];
void f (int u, int v){
    for (int i = max ((int)3, u) ; i <= min(u + 2, h) ; i ++){
        for (int j = max((int)3, v) ; j <= min (v + 2, w) ; j ++){
            cnt[{i, j}] ++;
        }
    }
}
signed main (){
    IOS
    cin >> h >> w >> n;
    while (n --){
        int u, v; cin >> u >> v;
        f(u, v);
    }
    int left = 0;
    for (auto i : cnt){
        ans[i.second]++;
        left ++;
    }
    cout << (h - 2) * (w - 2) - left << endl;
    for (int i = 1 ; i <= 9 ; i ++){
        cout << ans[i] << endl;
    }
    return 0;
}
