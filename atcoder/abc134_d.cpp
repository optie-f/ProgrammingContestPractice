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

const int INTINF = 2147483647;
const LL LLINF = 9223372036854775807;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

void solve() {
  int N; cin >> N;
  int boul=0;
  vector<int> a, b, ans;
  a.reserve(N+1); FILL(a, 0);
  b.reserve(N+1); FILL(b, 0);
  ans.reserve(N);

  REP1(i, N) cin >> a[i];
  // デフォルトが空であるとして, 後ろから見ていくことを考える
  // i の倍数の箱が条件を満たしていなかったら箱 i にボールを入れることで
  // 必ず「良いボールの入れ方」になることがわかる
  RREP1(i, N) {
      int cum = 0;
      int M = N/i;
      REP1(j, M) cum += b[i * j];  // i の倍数の箱: i*j s.t. j=1~N/i まで見る
      cum %= 2;
      if (cum != a[i]) {
          b[i] = 1;
          boul++;  // i番目の箱に入れないと条件を満たさない ならば 入れる
          ans.push_back(i);
      }
  }
  cout << boul << endl;
  REP0(i, boul) {
      cout << ans[i];
      if (i!=boul-1) cout << ' ';
  }
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