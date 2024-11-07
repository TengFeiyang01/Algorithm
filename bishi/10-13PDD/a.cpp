#include <bits/stdc++.h>
using namespace std;
int st[27];
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        memset(st, 0, sizeof st);
        string s;
        cin>>s;
        if(s.size()<26)
        {
            for(int i=0;i<s.size();i++)
            {
                st[s[i]-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                if(st[i]==0)
                {
                    s+='a'+i;
                    break;
                }
            }
            cout<<s<<endl;
        }
        else
        {
            string c;
            for(int i=25;i>=0;i--)
            {
                st[s[i]-'a']++;
                for(int j=s[i]-'a'+1;j<26;j++)
                {
                    if(st[j]==1)
                    {
                        for(int k=0;k<i;k++)
                        {
                            c+=s[k];
                        }
                        c+='a'+j;
                        break;
                    }
                }
                if(c.size()) break;
            }
            if(c.size()==0) cout<<s<<endl;
            else cout<<c<<endl;
        }
    }

    return 0;
}