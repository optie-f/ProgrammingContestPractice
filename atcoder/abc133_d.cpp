#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP0(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define RREP0(i,n) for(int i=n-1; i>=0; --i)
#define RREP1(i,n) for(int i=n; i>=1; --i)
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define FILL(c, v) std::fill((c).begin(),(c).end(), v)
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
  LL a, S = 0;
  vector<LL> A; A.reserve(N+1); FILL(A, 0);
  vector<LL> X; X.reserve(N+1); FILL(X, 0);
  REP1(i, N) { cin >> a; A[i] = a; S += a; }
  
  LL A_even=0;
  for (int i = 2; i < N; i+=2) A_even += A[i];
  X[1] = S - 2 * A_even;
  FOR(i, 1, N) X[i+1] = 2*A[i] - X[i];
  REP1(i, N) {
      cout << X[i];
      if (i!=N) cout << " ";
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