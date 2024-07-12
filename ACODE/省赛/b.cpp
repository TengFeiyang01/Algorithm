// #include <bits/stdc++.h>

// const int inf = 0x3f3f3f3f;
// using i64 = long long;

// void solve() {
//     int n, k;
//     std::cin >> n;
//     std::vector<i64> a(n), b(n);
//     for (int i = 0; i < n; ++i) {
//     	std::cin >> a[i];
//     }

//     std::vector<std::array<i64, 2>> dif(n);
//     for (int i = 0; i < n; ++i) {
//     	std::cin >> b[i];
//     	dif[i] = std::array<i64, 2>{b[i] - a[i], i};
//     }

//     std::sort(dif.begin(), dif.end());

//     int q;
//     std::cin >> q;
//     while (q--) {
//     	int m;
//     	std::cin >> m;
//     	std::vector<int> id(m);
//     	for (auto &x : id) {
//     		std::cin >> x;
//     	}
    	

//     }

// }

// int main() {
//     std::cin.sync_with_stdio(false);
//     std::cin.tie(0);
    
//     solve();

//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005],b[100005];
ll sum[100005],st[100005],id[100005];
pair<ll,ll> p[100005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];

    for(int i=1;i<=n;i++)
    {
        p[i].first=b[i]-a[i];
        p[i].second=i;
        sum[i]=sum[i-1]+p[i].first;
        a[i]+=a[i-1];
    }
    sort(p+1,p+n+1,greater<pair<ll,ll> >());
    for(int i=1;i<=n;i++) {
        st[p[i].second] = i;
    }

    int q;
    cin>>q;
    std::vector<ll> ans;
    for (int i = 0; i < q; ++i)
    {
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>id[i];
            id[i]=st[id[i]];
        }
        sort(id+1,id+m+1);
        ll sum1=0,cnt=0;
        for(int i=1;i<=m;i++)
        {
            if(id[i]<k+i)
            {
                sum1+=p[id[i]].first;
                cnt++;
            }
            else
            {
                break;
            }
        }
        ll res=a[n]+sum[cnt+k]-sum1;
        ans.push_back(res);
    }
    for (auto x : ans) {
        std::cout << x << "\n";
    }
}