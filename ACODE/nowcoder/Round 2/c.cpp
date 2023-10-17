#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

using namespace std;

int ans[9],m[9];
void update()
{
    for(int i=1;i<=8;i++)
        m[i]=max(m[i],ans[i]);
}
void down(int a,int b)
{
    int h=0;
    if(a==0)
    {
        for(int i=b;i<=b+1;i++)
        {  
            if(m[i]>=h){h=m[i];}
        }
        ans[b]=h+3;
        ans[b+1]=h+1;
    }
    else if(a==90)
    {
        h=max({m[b]+1,m[b+1],m[b+2]});
        ans[b]=h+1;
        ans[b+1]=h+1;
        ans[b+2]=h+1;
    }
    else if(a==180)
    {
        h=max(m[b],m[b+1]+2);
        ans[b]=h+1;
        ans[b+1]=h+1;
    }
    else
    {
        h=max({m[b],m[b+1],m[b+2]});
        ans[b]=h+1;
        ans[b+1]=h+1;
        ans[b+2]=h+2;
    }
}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;cin>>a>>b;
        down(a,b);
        update();
    }
    for(int i=1;i<=8;i++)cout<<ans[i]<<" ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
