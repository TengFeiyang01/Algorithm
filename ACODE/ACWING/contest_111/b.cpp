#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
const int N=2e5+10;
int n;
double ans,pos[4],tep[4],a[N],l,r;
bool check(double k)
{
    tep[1]=a[1]+k;
    int cnt=1;    
    for(int i=2;i<=n;i++){
        if(a[i]>tep[cnt]+k){
        if(cnt==3)return 0;
            cnt++;
            tep[cnt]=a[i]+k;    
        }    
    }
    return 1;
} 
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];  
    sort(a+1,a+n+1); 
    l=0,r=a[n];
    while(r-l>=eps){
        double mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            for(int i=1;i<=3;i++)pos[i]=tep[i];
            r=mid-eps;  
        }   
        else l=mid+eps;    
    }  
    cout<<fixed<<setprecision(6)<<ans<<endl<<pos[1]<<" "<<pos[2]<<' '<<pos[3]<<' ';
}