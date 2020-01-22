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

int test[16][16];

int bit_count (int bit, int N)
{
    int cnt = 0;
    REP0(i, N)
    {
        if (bit & (1 << i)) cnt++;
    }
    return cnt;
} 

void solve()
{
  int N; cin >> N;
  REP0(i, N)
  {
      int A; cin >> A;
      REP0(j, A)
      {
          int x; bool isHonest;
          cin >> x >> isHonest;
          test[i][x-1] = (isHonest) ? 1 : -1;
      }
  }

  int ans = 0;
//   honest/unkind を 1/0 にあてた bit 全探索
  for (int bit=0; bit<(1 << N); ++bit)
  {
      bool ok = true;
      REP0(i, N)
      {
        if (!(bit & (1 << i))) continue;
        REP0(j, N)
        {
            bool j_assumed_honest = bit & (1 << j);
            if (test[i][j]==-1 and j_assumed_honest) ok = false;
            if (test[i][j]==1 and !j_assumed_honest) ok = false;
        }
      }
      if (ok) ans = max(ans, bit_count(bit, N));
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