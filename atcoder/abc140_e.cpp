
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

// int M[10000][10000]; // max of [L][R]
// int X[10000][10000]; 

// void solve() {
//   int N; cin >> N;
//   REP0(i, N){
//     int p; cin >> p;
//     X[i][i] = p;
//     REP0(j, i+1) { // 0 ~ i-1 行 までの上△を埋める
//       FOR(k, j+1, i+1) { // j 行目を k = j+1 - i まで
//         if (k==j+1) {
//           X[j][k] = min(X[j][k-1], X[j+1][k]);
//           M[j][k] = max(X[j][k-1], X[j+1][k]);
//           } else {
//           if (M[j][k-1] <= X[k][k]) X[j][k] = M[j][k-1];
//           else if ((M[j][k-1] > X[k][k]) and (X[k][k] >= X[j][k-1])) X[j][k] = X[k][k];
//           else X[j][k] = X[j][k-1];
//         } 
//       }
//     }
//   }
//   int ans=0;
//   REP1(i, N) FOR(j, i+1, N+2) ans += X[i][j];
//   cout << ans << endl;
// }

void solve()
{
  // multiset<int> S; // 0<=j < i   s.t. P_i < P_j 
  // multiset<int> T; // i< j <=N+1 s.t. P_i < P_j
  // X_LR=P_i となるのは
  // ① w < L ≤ x < i ≤ R < y < z のときと
  // ② w < x ≤ L < i < y ≤ R < z のときのみ
  // つまり, P_iより大きい要素の添え字を範囲内にひとつ（x xor y）しか持たないときで
  // ①のケース数は (x-w)*(y-i); L,r が w < L ≤ x, i ≤ R < y でそれぞれ自由に動く
  // ②のケース数は (i-x)*(z-y) でカウントする
  ULL ans = 0;
  int N; cin >> N;

  map<int, int> P_index;
  REP1(i, N) {
    int p; cin >> p;
    P_index.insert(make_pair(p, i));
  }
  multiset<int> checked_ind;
  checked_ind.insert(0); checked_ind.insert(0);
  checked_ind.insert(N+1); checked_ind.insert(N+1);

  decltype(checked_ind)::iterator ptr_x;
  decltype(checked_ind)::iterator ptr_y;

  RREP1(P_i, N){
    int i = P_index.at(P_i);
    ptr_y = checked_ind.upper_bound(i);
    // lower_bound は条件を満たす *最初の要素* を指すので
    // set に対して使うと最小値を取ってきてしまう
    ptr_x = prev(ptr_y);
    // int だとはみ出る
    LL cnt = (*ptr_x - *prev(ptr_x)) * (*ptr_y - i);
    cnt += (i - *ptr_x) * (*next(ptr_y) - *ptr_y);
    ans += cnt * P_i;
    checked_ind.insert(i);
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
