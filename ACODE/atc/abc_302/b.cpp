#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>

using namespace std;
typedef long long LL;
#define int long long
typedef pair<int,int> PII;
const int N=1000010;

char a[1010][1010];
deque<PII>q;
int dx[8]={-1,0,0,1,-1,1,-1,1},dy[8]={0,-1,1,0,-1,-1,1,1};
char str[4]={'n','u','k','e'};
int n,m;
bool check(int x,int y,int now,int w){
    int xx=x+dx[w],yy=y+dy[w];
    if(xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy]==str[now]){
        q.push_back({xx,yy});
        if(check(xx,yy,now+1,w) || now==3){
            return true;
        }
        q.pop_back();

    }
    return false;
}
void solve(){

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='s'){
                q.push_back({i,j});
                for(int k=0;k<8;k++){
                    if(check(i,j,0,k)){
                        while(q.size()){
                            cout<<q.front().first<<" "<<q.front().second<<endl;
                            q.pop_front();
                        }
                        return ;
                    }
                }

                q.pop_front();
            }
        }
    }
}
signed main(){
    int t;
    //cin>>t;
    //while(t--){
    solve();
    //}
}