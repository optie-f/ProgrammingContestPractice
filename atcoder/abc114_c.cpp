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
const LL LLINF = 1e18;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int N;

int dfs(int rem_digit, string ptn, int s3, int s5, int s7)
{
    if (rem_digit==0)
    {
        if (s3 * s5 * s7 > 0 and toInt(ptn) <= N) return 1;
        else return 0;
    }
    int p1 = dfs(rem_digit - 1, ptn + "3", s3 + 1, s5, s7);
    int p2 = dfs(rem_digit - 1, ptn + "5", s3, s5 + 1, s7);
    int p3 = dfs(rem_digit - 1, ptn + "7", s3, s5, s7 + 1); 
    return p1 + p2 + p3;
}

void solve()
{
    cin >> N;

    int digit = 1; int tmp = N;
    while(tmp/10>0) { digit++; tmp /= 10; }

    int ans = 0;
    FOR(i, 3, digit+1)
    { // 3桁から N の桁数まで
        ans += dfs(i, "", 0, 0, 0);
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