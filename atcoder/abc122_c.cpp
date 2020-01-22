#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP0(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define RREP0(i,n) for(int i=n-1; i>=0; --i)
#define RREP1(i,n) for(int i=n; i>=1; --i)
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define FILL(c, v) fill((c).begin(),(c).end(), v)
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define CLR(a) memset((a), 0 ,sizeof(a))

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long LL;
typedef unsigned long long ULL;

const int INTINF = 2147483647;
const LL LLINF = 9223372036854775807;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int dp[100001]; // 1-iに出現するAC数

void solve()
{
  int N, Q; cin >> N >> Q;
  char s_prev = '\0';
  REP1(i, N)
  {
      char s; cin >> s;
      dp[i] = dp[i-1];
      if (s_prev=='A' and s=='C') dp[i]++;
      s_prev = s;
  }
  
  REP0(i, Q) {
      int l, r; cin >> l >> r;
      // 解説と添字が異なるが、こちらは "C" を基準にカウントしているため
      cout << dp[r] - dp[l] << endl;
  }
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(10);
    solve();
    return 0;
}