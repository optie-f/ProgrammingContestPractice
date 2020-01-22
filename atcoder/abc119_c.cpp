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

const int INTINF = 1e9;
const LL LLINF = 9223372036854775807;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int l[10];
int N, A, B, C;

int dfs(int i, int a, int b, int c)
{
    if (i == N) 
    {
        // 竹を伸縮させるコスト. ただしどれかを無から生成し始めるパタンは棄却し、
        // 無の材料に合成したコストも引いておく
        return ((a*b*c>0) ? abs(A-a) + abs(B-b) + abs(C-c) - 30 : (int)1e9);
    }
    int ptn0 = dfs(i+1, a, b, c); // i本目の竹を無視する
    // 竹をa/b/cの材料へ合成する
    int ptn1 = dfs(i+1, a + l[i], b, c) + 10;
    int ptn2 = dfs(i+1, a, b + l[i], c) + 10;
    int ptn3 = dfs(i+1, a, b, c + l[i]) + 10;
    return min(min(ptn0, ptn1), min(ptn2, ptn3));
}

void solve()
{
  cin >> N >> A >> B >> C;
  REP0(i, N) cin >> l[i];
  cout << dfs(0, 0, 0, 0) << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(10);
    solve();
    return 0;
}