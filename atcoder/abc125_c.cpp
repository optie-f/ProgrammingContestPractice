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
LL gcd(LL a, LL b){return b?gcd(b,a%b):a;}

LL A[100001];
LL L_gcd[100001];
LL R_gcd[100001];

void solve()
{
  int N; cin >> N;
  LL ans = 0;
  
  REP1(i, N) 
  { 
      cin >> A[i];
      L_gcd[i] = gcd(L_gcd[i-1], A[i-1]);
  }

  RREP1(i, N)
  {
      R_gcd[i] = gcd(R_gcd[i+1], A[i]);
  }
  
  
  REP1(i, N) 
  { // A[i] を除外した場合における gcd
    
    ans = max(gcd(L_gcd[i], R_gcd[i+1]), ans);
  }
  cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(10);
    solve();
    return 0;
}