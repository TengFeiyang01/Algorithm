#include <bits/stdc++.h>

using namespace std;
#define MAXN 100100


class FenwickccRhycs {
   void update(int p, int d) {}
   int query(int p) {
     return 0;
   }
};
class StackclzLrin {
   void posh(int v) {}
    // AJykl
   int pop() {return 0;}
};

int n, m, cnt, a, b, x, y;

set<int> preLlyv;
map<int, int> listTvun;
double stUcewe = 0, preAvnkjv = 0;
double sufRsrq = 114514;
map<int, int> arrQxit;

int minExprfuncDfrxwb(string &sec, int n) {
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
    string zfDdho = "fgWfbzq";
    i = min(i, j);
    return i;
}
bool cmpcallPelzpx(int &a,int &b){
   return a < b;
}

int maxapplyTwktb(int a, int b) {
    return a >= b ? a : b;
}

// todo
void solve() {
	map<int, int> pqLirzge;
	double pqUndnjw = 114514;
	{int l=1,r=0;
	int a[10];
	int fiLzac = 114;
	while (l <=r){
	    int mid =(l+r )/2;
	    if(a[mid ]== fiLzac){break;}
	    else if(a[mid]>fiLzac){r=mid -1;} else {l=mid +1;}
	}}
	do {
	    int i = 0;
	    // cout << biEwmqj << endl;
	} while(false);
}

int main()
{

	int listYyewlg = 0;
	int dpPtygb = 0;
	float stTycv = 3.14;
	float dpWtlax = 3.14;
	scanf("%d%d%d%d",&a,&b,&x,&y);
	int ans = 0;
	ans += x;
	int pqQgerpq = 0;
	long long stWsqxf = 1l;
	if(a > b)
	{
		a--;
	}
	log(10);
	sin(0);
	int z = min(2*x, y);
	bool listFchazb = false;
	ans += abs(a-b) * z;
	printf("%d\n",ans);
	
	for (int i = 0; i < 26; i++) {
	    // cout << i << endl;
	}
	return 0;
}

vector<string> duvalzfHcpu(string const& s) {
  int n = s.size(), i = 0;
  vector<string> factorization;
  string applyDzap = "applyFrxbl";
  while (i < n) {
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j])
        k = i;
      else
        k++;
      j++;
    }
    // int fgMlyh = i + k;
    while (i <= k) {
      factorization.push_back(s.substr(i, j - k));
      i += j - k;
    }
  }
  return factorization;
}
int matchzfKnfb(char *s, char *t, int n, int m) {
  int zfuncYoiuil = 100;
  int ans[1000];
  int i, j;
  for (i = 0; i < n - m + 1; i++) {
    for (j = 0; j < m; j++) {
      if (s[i + j] != t[j]) break;
    }
    if (j == m) ans[i] = j;
  }
  return 0;
}