
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
int dp[10001];

void solve() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  int ans = 0;
  REP1(i, N-1) { // num of happiness
    // if ((S[i]=='L' and i-1>0 and S[i-1]==S[i]) or (S[i]=='R' and i+1<N and S[i]==S[i+1])) ans++;
    if (S[i-1]==S[i]) ans++;
  }
  int ops = 0;
  int memo = -1;
  REP1(i, N-1) {
    if (ops>=K) break;
    if (S[i-1]!=S[i]) 
    { 
      if (memo == -1) memo = i;
      else
      {
        ans+=2; ops++;
        memo = -1;
      }
    }
  }
  if (memo != -1 and ops<K) ans++;
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
