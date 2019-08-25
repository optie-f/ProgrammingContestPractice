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

static const ULL MOD = 1000000007LL;
int n;
char s[100005];
uint64_t dp[100005][13];

void solve() {
    uint64_t ans=0;
    scanf("%s", s);
    n = strlen(s);
    // dp[i][j] := 先頭 i 文字として考えられるもののうち，13 で割ったあまりが j であるものの数
    dp[0][0] = 1;
    REP0(i, n) {
        int c; // i 文字目の数
        if (s[i] == '?') c = -1;
        else c = s[i] - '0';  // toInt
        REP0(j, 10) {
            if (c != -1 and c != j) continue;
            REP0(ki, 13) {
                // 「前から i 文字目までからなる数のうち, 13 で割ったあまりが ki であるものの総数」
                // から、 「i+1 文字目までからなる…余りkiであるような総数」を求めることができる
                dp[i+1][(ki*10+j) % 13] += dp[i][ki];
            }
        }
        REP0(j, 13) dp[i+1][j] %= MOD;
    }
    ans = dp[n][5];
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
