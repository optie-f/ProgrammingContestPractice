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

int H[101][101];

void solve()
{
    int N; cin >> N;
    REP1(i, N) 
    {
        int h; cin >> h;
        REP0(j, h) H[i][j]++;
    }

    int ans = 0;

    REP0(h, 100)
    {
        int delta = 0;
        REP1(i, N)
        {
            // 下から順に水平に舐めて、新たな山を発見したとき
            if (H[i-1][h] == 0 and H[i][h] == 1) delta++;
        }
        ans += delta;
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