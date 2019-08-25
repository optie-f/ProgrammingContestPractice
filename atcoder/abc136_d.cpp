#include <bits/stdc++.h>
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

const int INTINF = 2147483647;
const LL LLINF = 9223372036854775807;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

void solve() {
  char s_i, s_prev;
  int cntEven=0; int cntOdd=0;
  int holeEven, holeOdd;
  vector<int> ans; ans.reserve(100001); FILL(ans, 0);
  int i=0;
  while (cin >> s_i)
  {
    if (i != 0)
    {
      if (s_prev=='R' and s_i=='L')
      {
        if (i%2==0) { holeEven=i; holeOdd =i-1; }
        else        { holeOdd =i; holeEven=i-1; }
      }
      if (s_prev=='L' and s_i=='R')
      {
        ans[holeEven] = cntEven;
        ans[holeOdd] = cntOdd;
        cntEven = cntOdd = 0;
      }
    }
    (i%2==0) ? cntEven++ : cntOdd++;
    s_prev = s_i;
    i++;
  }
  ans[holeEven] = cntEven;
  ans[holeOdd] = cntOdd;
  REP0(j, i) cout << ans[j] << ((j==i-1) ?  "" : " ");
  cout << endl;
}

int main(int argc, char const *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout<<std::fixed<<std::setprecision(10);
  solve();
  return 0;
}