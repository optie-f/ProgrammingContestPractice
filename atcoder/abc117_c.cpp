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

void solve()
{
    int N, M; cin >> N >> M;
    
    vector<int> A; A.reserve(M);
    REP0(i, M) { int a; cin >> a; A.push_back(a); }
    SORT(A);
    
    vector<int> dist2next; dist2next.reserve(M);
    REP0(i, M-1) dist2next.push_back( abs(A[i+1] - A[i]) ); 
    
    SORT(dist2next);
    
    int ans = 0;
    REP0(i, M-N) ans += dist2next[i];

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