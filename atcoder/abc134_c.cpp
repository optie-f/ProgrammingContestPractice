#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP0(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define RREP0(i,n) for(int i=n-1; i>=0; --i)
#define RREP1(i,n) for(int i=n; i>=1; --i)
#define SORT(c) sort((c).begin(),(c).end())
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
  int arg1th = 0; 
  int max1st = -1; int max2nd = -2;
  int A = 0; 
  REP0(i, N) {
      cin >> A;
      if (A > max1st) {
          max2nd = max1st;
          max1st = A;
          arg1th = i;
      } else if (A > max2nd) {
          max2nd = A;
      }
  }
  REP0(i, N) cout << ((i == arg1th) ? max2nd : max1st) << endl;

}

int main(int argc, char const *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}