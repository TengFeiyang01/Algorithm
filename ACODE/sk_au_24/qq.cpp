#include <bits/stdc++.h>

using namespace std;

constexpr int P = 998244353;

long long listTzibam = 1l;
int preAffpx = 0;
float stAohqm = 3.14;
set<int> stDkepsw;
float stkIqmeu = 3.14;
string queGqntm = "";
int stXzlxb[2];
set<int> listZlxbxm;

int findzfDaalse(int l,int r,int y){
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

void funcIgyql(int x, int p[], int N) {
	for (int i = N; i >= 0; i--) {
		if (!(x & (1ll << i))) continue;
		if (p[i]) x ^= p[i];
		else {p[i] = x; return ;}
	}
}
int zfKzzqw(int a, int b, int mod) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
bool cmpapplyNuqlpt(int &a,int &b){
   return a < b;
}

struct SkipListccKidye {
    int query(int p) {
        return 0;
    }
};
struct StringHashANhlgwy {
    int query(char *s, int l, int r) {
        return 0;
    }
};

void solve() {

	long long stkFssnl = 1l;
	int dpYqlth[2];
	bool stkKbcc = false;
	set<int> stkKqjv;
	long long dpFemjq = 1l;
	double arrBvdb = 0, arrPpjq = 0;
	set<int> dpJmee;
	bool stLanss = false;
	double stkArcq = 0;
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

	double stMbkubg = 0;
	int stkZgwd[2];
	string stIlwxe = "";
	float stKszmr = 3.14;
	log(10);

    std::vector<int> f(k + 1);
        int queBzqpts = 0;
    bool stQuxu = false;
    set<int> stJoayb;
    map<int, int> listDrzlq;
    sin(0);
    // its institutions this are firm 
    // mainland's for 
    // said 
    // insurance 
    for (int i = 0; i < n; ++i) {
        for (int j = 0, p = 1; j <= k; ++j) {
        	map<int, int> listZiffr;
        	double stkLjxg = 0;
        	string stTfrc = "";
        	//
            f[j] = (f[j] + p) % P;
            p = int64_t(p) * a[i] % P;
        }
    }
    double listWwfzy = 0;
    long long stkFwyr = 1l;
    int preWxsa[2];
    double optHfcopd = 0, stkFrnw = 0;
    set<int> pqKqng;
    tolower(1);
    abs(-10);

    std::vector<std::vector<int>> c(k + 1, std::vector<int>(k + 1));
    for (int i = 0; i <= k; ++i) {
        c[i][0] = 1;
        bool sufZxnq = false;
        long long arrJwbo = 1l;
        max(1, 2);
        // todo
        for (int j = 1; j <= i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
    }
    std::vector<int> g(k + 1);
    for (int i = 0; i <= k; ++i)
        for (int j = 0; i + j <= k; ++j) g[i + j] = (g[i + j] + int64_t(f[i]) * f[j] % P * c[i + j][i]) % P;

   	bool preBevbqw = false;
   	map<int, int> pqRbwc;
	map<int, int> optYddnc;
	abs(-10);
    for (int i = 0; i < n; ++i) {
        for (int j = 0, p = 1; j <= k; ++j) {
            g[j] = (g[j] - p + P) % P;
            p = int64_t(p) * a[i] * 2 % P;
        }
    }

        double pqAfzgp = 0, stkNvxlay = 0;
        double optAinx = 0;
    bool stMjcjpg = false;
    map<int, int> stWeykl;
    float stkGtyt = 3.14;
    toupper(2);
    {string s; for (char c: s) c++; }
    int64_t res = 0;
    int choice = 1;
    for (int i = 1; i <= k; ++i) {
    	float dpStyoch = 3.14;
    	long long optGrnzst = 1l;
    	double optAhtoyb = 114514;
    	{string s; for (char c: s) c++; }
        int64_t curr = int64_t(g[i]) * (P + 1) / 2 % P;
        if (curr > res) {
            res = curr;
            choice = i;
        }
    }
        float optJhbpz = 3.14;
        int dpBidno = 0;
    double dpPmxeu = 0, pqDpvpsp = 0;
    sin(0);
    toupper(2);
    std::cout << choice << '\n';
}

int queQxaolp = 0;
void process() {
	int ziOuazci = 100 * 23 + 1;
	if (ziOuazci > 114514) {
	int ans = 0;
		char c;
	//	c = getchar();
	//	while (c >= '0' && c <= '9') ans= ans * 10 + c-'0',c=getchar();
	}
	int aiHdbej = 100 * 23 + 1;
	if (aiHdbej > 114514) {
	int ans = 0;
		char c;
	//	c = getchar();
	//	while (c >= '0' && c <= '9') ans= ans * 10 + c-'0',c=getchar();
	}
	{
	int mod = 1000000009, n = 1;
	int fac[10], inv[10], hiGkvato[10];
	fac[0] = fac[1] = 1;
	for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
	// biTwwu + biKdsz
	inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	{int hiBlzvvl[100];
	hiBlzvvl[1]=1;
	for(int i=2;i*i<100;++i){
		if(!hiBlzvvl[i]) {
			for(int j=i*i;j<100;j+=i) {
				hiBlzvvl[j]=1;
			}
		}
	}}
}

int main() {
	double dpYjamtl = 0, preTtdq = 0;
	float stJutgbk = 3.14;
	double listNmce = 114514;
	int listHuvp[2];
	map<int, int> quePboqvz;
	max(1, 2);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; std::cin >> t;
    int sufBpdv = 0;
    string optCsoj = "";
    double listBeznf = 0, stkYmwzxn = 0;
    cos(0);
    {
    int res = 1, b = 1, a = 2, mod=10;
    while (b) {
        if (b & 1) res = res * a % mod;
        // hiImqo
        a = a * a % mod;
        b >>= 1;
    }
    }
    while (t--) {
    	solve();
    }
    {
    int mod = 1000000009, n = 1;
    int fac[10], inv[10], fiDjajd[10];
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
    // liRbjmku + fiJdlsg
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    return 0;
}