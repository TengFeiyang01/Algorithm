#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
string a[205][205];
int b[200005];
int e[200005],h[200005],idx,ne[200005],w[200005],dist[200005],st[200005];
int n,m;
void add(int l,int r,int c)
{
    e[idx]=r,w[idx]=c,ne[idx]=h[l],h[l]=idx++;
}
int ex(int x,int y)
{
    return (x-1)*m+y;
}
int num(string s)
{
    int k=0;
    for(int i=0;i<s.size();i++)
    {
        k=k*10+(s[i]-'0');
    }
    return k;
}
int dijkstra(int s,int ee)
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, s});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    memset(st,0,sizeof(st));
    for(int i=1;i<=ex(n,m);i++)
    {
        if(b[i]==-2) heap.push({dist[i],i});
    }
    for(int i=1;i<=ex(n,m);i++)
    {
        if(b[i]!=-2) dist[i]=0x3f3f3f3f;
    }
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[ee] == 0x3f3f3f3f) return -1;
    return dist[ee];
}
int main()
{
    memset(h,-1,sizeof(h));
    cin>>n>>m;
    int s,e;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            int k=ex(i,j);
            if(a[i][j]=="S")
            {
                b[k]=-4;
                s=k;
            }
            else if(a[i][j]=="B")
            {
                b[k]=-1;
            }
            else if(a[i][j]=="E")
            {
                b[k]=-3;
                e=k;
            }
            else if(a[i][j]=="C")
            {
                b[k]=-2;
            }
            else
            {
                b[k]=num(a[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i+1<=n&&a[i][j]!="B"&&a[i+1][j]!="B")
            {
                int b1=max(0,b[ex(i+1,j)]);
                int b2=max(0,b[ex(i,j)]);
                add(ex(i,j),ex(i+1,j),b1);
                add(ex(i+1,j),ex(i,j),b2);
            }
            if(j+1<=m&&a[i][j]!="B"&&a[i][j+1]!="B")
            {
                int b1=max(0,b[ex(i,j+1)]);
                int b2=max(0,b[ex(i,j)]);
                add(ex(i,j),ex(i,j+1),b1);
                add(ex(i,j+1),ex(i,j),b2);
            }
        }
    }
    cout<<dijkstra(s,e);
}