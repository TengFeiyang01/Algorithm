#include<bits/stdc++.h>
using namespace std;
int main(){
    long long m,n,i,b[10],c[10],a[1010],ans=1;
    scanf("%lld %lld",&m,&n);
    for(i=1;i<=m;i++){
        scanf("%lld",&b[i]);
        c[b[i]]=i;
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]=c[a[i]];
    }
    for(i=1;i<n;i++){
        if(a[i]+1<a[i+1]){
            ans=0;
            break;
        }
        if(a[i]>=a[i+1])ans++;
    }
    printf("%lld",ans);
    return 0;
}