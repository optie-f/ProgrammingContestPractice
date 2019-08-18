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
  int N, Q, a, b, p, x;
  cin >> N >> Q;
  vector<int> counter; counter.reserve(N+1); FILL(counter, 0);
  vector<int> parentOf; parentOf.reserve(N+1); FILL(parentOf, -1);
  REP0(i, N-1) {
      cin >> a >> b;
      parentOf[b] = a;
  }
  REP0(i, Q) {
      cin >> p >> x;
      counter[p] += x;
  }
  FOR(i, 2, N+1) {
      counter[i] += counter[parentOf[i]];
  }
  REP1(i, N) cout << counter[i] << ((i!=N)? " " : "");
  cout << endl;

}

int main(int argc, char const *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}