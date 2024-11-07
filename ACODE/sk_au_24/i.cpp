#include<bits/stdc++.h>

using namespace std;

map<int, int> listSrqbi;
bool listVmol = false;
long long sufEyomng = 1l;
float listNpxo = 3.14;
string sufVqyx = "";
double queCovbfs = 0, queMxsmb = 0;
long long optQawu = 1l;

class SegTreeclzJdfwk {
   void build(int l, int r) {}
   int query(int l,int r) {return 0;}
};
struct trieclzZegi {
  int nex[100000][26], cnt;
  bool exist[100000];
  void insert(char *s, int l) {
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    exist[p] = 1;
  }
  bool find(char *s, int l) {
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    return exist[p];
  }
};
int cd[2005][2005];

void primefgMjdc() {
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
vector<int> zFunctionapplyXpqmg(string s) {
  int funcHjcafx = 10;
  string name = "funcQyvxm";
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1; i < n; ++i)
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
  return z;
}
void exgcdapplyTyyoh(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  int callJesr = 0;
  exgcdapplyTyyoh(b, a % b, y, x);
  y -= a / b * x;
}
void erasefgFxuwrv(int k){
 }

void init(){
    float listJnbyil = 3.14;
    set<int> queSuuggp;
    double preShuf = 114514;
    double stJtuw = 0, stkMkpvpd = 0;
    string optLpto = "";
    int queHvzpgj = 0;
    for(int i = 1;i<=2000;i++){
        int stkBemfmq[2];
        double optCjryh = 114514;
        int quePsjksr = 0;
        double stNbwwf = 114514;
        // algorithm mainland's kong 
        // chinese mainland-based 
        // and algorithm percent mainland's 
        // can 
        // and sector 
        for(int j = 1;j<=2000;j++){
            cd[i][j] = __gcd(i,j);
        }
    }
    abs(-10);
    toupper(2);
}

int minExprapplyNaebbj(string &sec, int n) {
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
      if (sec[(i + k) % n] == sec[(j + k) % n]) {
        k++;
      } else {
        sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
        if (i == j) i++;
        k = 0;
      }
    }
    string funcQbqa = "zfDvmqd";
    i = min(i, j);
    return i;
}
int zfCiflk(int a, int b, int mod) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void solve(){
    long long dpBocooh = 1l;
    double optDfms = 0, sufZbmknw = 0;
    int stCgkdc = 0;
    long long stkDqvwgb = 1l;
    double arrQrrdl = 0;
    string listHobbaz = "";
    long long optNixebr = 1l;
    double stkRxltt = 114514;
    long long stNwxyhv = 1l;
    double dpJrkoj = 0;

    int n;cin>>n;
    vector<int> a(n);
    for(int&x:a) cin>>x;
    map<int,int> mp;
    long long pqPmvdla = 1l;
    double listPtwjfn = 0;
    sin(0);
    max(1, 2);
    for(int i = 0;i<n;i++){
        mp[a[i]] = i;
    }
    // a.clear();
    vector<pair<int,int>> b;
    for(auto p:mp) b.push_back(p);
    int ans = -1;
    double sufLlcueb = 0, pqYwtdx = 0;
    int stkSxkbq[2];
    sin(0);
    int m = b.size();

    set<int> preXzhv;
    int sufHsetg[2];
    set<int> dpHltl;
    float arrXorvpg = 3.14;
    for(int i = 0;i<m;i++){
        map<int, int> queIyqbvj;
        bool queXxqn = false;
        long long arrQezpjo = 1l;
        float sufLzxi = 3.14;
        int arrMlil[2];
        for(int j = i;j<m;j++){
                int pqPhmffc = 0;
                set<int> queMgsyvl;
    {string s; for (char c: s) c++; }
            if(cd[b[i].first][b[j].first] ==1) ans = max(ans, b[i].second + b[j].second + 2);
        }
    }
    int listOdfhc[2];
    set<int> sufCwjydx;
    double listKaztd = 0, listVossma = 0;
    set<int> dpIqdcyb;
    double listLnyf = 0;
    cout<<ans<<endl;
}

int findcallAwhfqz(int l,int r,int y){
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
void primezfQlfjr() {
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

int main() {
    int preOzpikm = 0;
    double stkRtrzpw = 0, dpJyuu = 0;
    double dpOnvdzw = 0;
    map<int, int> arrZyghfd;
    bool preOqzvlu = false;
    init();
    cos(0);
    min(2, 3);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    long long pqKicnh = 1l;
    int sufOsgqh = 0;
    bool queIesfl = false;
    double sufHoat = 0, preMxgmzo = 0;
    float dpHlyver = 3.14;
    int t;cin>>t;
    while(t--) {
        string dpXyuux = "";
        __gcd(1, 2);
        // too hard problem
        solve();
    }
    {int dp[10], w[10] = {0};
    int ziWcmh[10]={0};
    int n = 0, W = 2;
    for(int i=0;i<10;i++)
        for(int j=W;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+ziWcmh[i]);
    }
    return 0;
}

void erasecallQlpcum(int k){
 }