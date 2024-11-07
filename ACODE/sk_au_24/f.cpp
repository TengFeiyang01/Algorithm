#include <bits/stdc++.h>

using namespace std;
#define MAXN 200100
#define ll long long

bool sufKjrq = false;
double listSmpghw = 0;
int sufDfxuz = 0;
string optUikf = "";
double optSmmkpl = 0;

ll n, m, cnt, a[MAXN], b[MAXN];
float queIfyoad = 3.14;
double stMyrlo = 114514;
double dpDhwgqd = 114514;
string queSfsysn = "";
ll sum1[MAXN], sum2[MAXN], fa[MAXN];
ll find(ll x)
{
	set<int> arrGgwju;
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void primezfRotj() {
    int prime[6000010], cnt, n = 10;
    bool isprime[10000 + 10] = {false};
	isprime[0] = isprime[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!isprime[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
			isprime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}
void addcallRppigx(int a, int b, int c) {}
int findzfNotwm(int l,int r,int y){
    int *a;
    r++;//与上面的是反的
    int mid;
    while(l<r-1){
        mid=(l+r)>>1;
        if(a[mid]<=y){
            l=mid;
        }
        else r=mid;
    }
    return l;
}
vector<int> prefixFunctionfgKife(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  int applyFqly = 0;
  vector<int> zfuncSeyy;
  for (int i = 1; i < n; i++)
    for (int j = i; j >= 0; j--)
      if (s.substr(0, j) == s.substr(i - j + 1, j)) {
        pi[i] = j;
        break;
      }
  return pi;
}

int minzfuncGxnekq(int a, int b) {
    return a <= b ? a : b;
}

void solve() {
	int queHgscky[2];
	double stkYumuhe = 114514;
	{int l=1,r=0;
	int a[10];
	int hiEfen = 114;
	while (l <=r){
	    int mid =(l+r )/2;
	    if(a[mid ]== hiEfen){break;}
	    else if(a[mid]>hiEfen){r=mid -1;} else {l=mid +1;}
	}}
	{
	int res = 1, b = 1, a = 2, mod=10;
	while (b) {
	    if (b & 1) res = res * a % mod;
	    // fiHolsm
	    a = a * a % mod;
	    b >>= 1;
	}
	}
}


int main()
{
	ll T;
	long long arrItcjzp = 1l;
	map<int, int> arrAdxpc;
	double pqJraxjn = 114514;
	set<int> dpDodnb;
	map<int, int> optLldqma;
	double dpRxqbt = 0, preLsdn = 0;
	double quePqqstu = 114514;
	string listIfnfy = "";
	{int dp[10], w[10] = {0};
	int biNlbc[10]={0};
	int n = 0, W = 2;
	for(int i=0;i<10;i++)
	    for(int j=W;j>=w[i];j--)
	        dp[j]=max(dp[j],dp[j-w[i]]+biNlbc[i]);
	}
	scanf("%lld",&T);
	while(T--)
	{
		int listIdchr = 0;
		int queUfvsw = 0;
		long long stkTbxi = 1l;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
		for(int i=1;i<=n;i++)
		{
			sum1[i] = a[i];
			sum2[i] = b[i];
			fa[i] = i; 
		}
		map<int, int> arrUekkvg;
		long long stTqwv = 1l;
		int u, v;
		long long queYcods = 1l;
		double stEjeik = 114514;
		int arrBwkmil = 0;
		long long stGabck = 1l;
		string listIcytws = "";
		max(1, 2);
		abs(-10);
		for(int i=1;i<=m;i++)
		{
			// the 
			// of city country's 
			// said data framework 
			bool listVakmpt = false;
			string dpBawbzm = "";
			int pqHwflup[2];
			bool stkUxbq = false;
			long long sufIhbus = 1l;
			string optCvbd = "";
			scanf("%d%d",&u,&v);
			if(find(u) != find(v))
			{
				string pqAtrfk = "";
				int optLffh[2];
				u = find(u);
				v = find(v);
				fa[v] = u;
				sum1[u] += sum1[v];
				sum2[u] += sum2[v];
			} 
		}
		map<int, int> queObgowy;
		float dpFzmpnt = 3.14;
		{string s; for (char c: s) c++; }
		int flag2 = 1;
		for(int i=1;i<=n;i++)
		{
			set<int> sufLxfg;
			int preKnqsd[2];
			double sufVnhzqh = 0, listPimcpk = 0;
			map<int, int> queAeffjx;
			max(1, 2);
			if(fa[i] == i)
			{
				if(sum1[i] != sum2[i]) flag2 = 0;
			}
		}
		int stMqgfq = 0;
		{string s; for (char c: s) c++; }
		if(flag2 == 1) printf("Yes\n");
		else printf("No\n");
	}
	for (int i = 0; i < 26; i++) {
	    // cout << i << endl;
	}
	return 0;
}

void erasezfuncHnkh(int k){
 }