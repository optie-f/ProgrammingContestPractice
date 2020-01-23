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

struct city
{
    int index;
    int pref;
    int year;
    string name;

    city(int i, int p, int y): index(i), pref(p), year(y) {}
};

string last(string s, int n)
{
    string result=""s;
    REP1(i, n)
    {
        result = s[s.length() - i] + result;
    }
    return result;
}

void solve()
{
    int N, M; cin >> N >> M;
    vector<city> cities; cities.reserve(M);
    REP1(i, M)
    {
        int P, Y; cin >> P >> Y;
        city c(i, P, Y);
        cities.push_back(c);
    }

    auto sort_func_1 = [](city c1, city c2)
    {
        return (c1.pref == c2.pref) ? c1.year < c2.year : c1.pref < c2.pref;
    };

    sort(cities.begin(), cities.end(), sort_func_1);

    int num = 1;
    int prev_pref = 0;
    REP0(i, M)
    {
        if ( cities[i].pref != prev_pref ) { num = 1; prev_pref = cities[i].pref; }
        string zeros = "000000"s;
        cities[i].name = last(zeros + toString(cities[i].pref), 6) + last(zeros + toString(num), 6);
        num++;
    }

    auto sort_func_2 = [](city c1, city c2)
    {
        return c1.index < c2.index;
    };


    sort(cities.begin(), cities.end(), sort_func_2);

    REP0(i, M) cout << cities[i].name << endl;

}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(10);
    solve();
    return 0;
}