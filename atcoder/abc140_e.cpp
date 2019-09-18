
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

int M[10000][10000]; // max of [L][R]
int X[10000][10000]; 

void solve() {
  int N; cin >> N;
  REP0(i, N){
    int p; cin >> p;
    X[i][i] = p;
    REP0(j, i+1) { // 0 ~ i-1 行 までの上△を埋める
      FOR(k, j+1, i+1) { // j 行目を k = j+1 - i まで
        if (k==j+1) {
          X[j][k] = min(X[j][k-1], X[j+1][k]);
          M[j][k] = max(X[j][k-1], X[j+1][k]);
          } else {
          if (M[j][k-1] <= X[k][k]) X[j][k] = M[j][k-1];
          else if ((M[j][k-1] > X[k][k]) and (X[k][k] >= X[j][k-1])) X[j][k] = X[k][k];
          else X[j][k] = X[j][k-1];
        } 
      }
    }
  }
  int ans=0;
  REP1(i, N-1) FOR(j, i, N) ans += X[i][j];
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
