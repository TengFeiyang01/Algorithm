#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=7;i++)
    {
        long long l=0,r=n;
        while(l<r)
        {
            long long mid=l+r+1>>1;
            if(mid==n&&mid*i==m) l=mid;
            else{
                double k=(m-mid*i)*1.0/(n-mid);
                if(k>=1&&k<=7) l=mid;
                else r=mid-1;
            }
        }
        cout<<l<<endl;
    }
}