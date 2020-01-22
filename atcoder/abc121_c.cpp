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

void solve()
{
  int N, M; cin >> N >> M;
  LL ans = 0;
  vector<pair<LL, int>> shops; shops.reserve(N);
  REP0(i, N)
  {
      LL A; int B; cin >> A >> B;
      pair<LL, int> shop = make_pair(A, B);
      shops.push_back(shop);
  }

  auto sort_func = [](pair<LL, int> A, pair<LL, int> B){
      return A.first < B.first;
  };

  sort(shops.begin(), shops.end(), sort_func);

  for (auto shop : shops)
  {
     if (M == 0) break;
     if (M >= shop.second) {
         M -= shop.second;
         ans += shop.second * shop.first;
     } else {
         ans += M * shop.first;
         M = 0;
     }
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