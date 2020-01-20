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

int cities[9][2];

double dist(int i, int j)
{
    double dx2 = pow(cities[i][0] - cities[j][0], 2);
    double dy2 = pow(cities[i][1] - cities[j][1], 2);
    double dist = sqrt(dx2 + dy2);
    return dist;
}


void solve()
{
  int N; cin >> N;
  int fact_N = 1;
  vector<int> indices(N);
  double sum = 0.0;

  REP1(i, N)
  {
      fact_N *= i;
      cin >> cities[i][0] >> cities[i][1];
      indices[i-1] = i;
  }
  
  do {
      REP0(i, N-1) sum += dist( indices[i], indices[i+1] );
  } while (next_permutation(indices.begin(), indices.end()));
  
  cout << (sum / fact_N) << endl;
}

int main(int argc, char const *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout<<std::fixed<<std::setprecision(10);
  solve();
  return 0;
}