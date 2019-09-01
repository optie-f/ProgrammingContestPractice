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

vector<queue<int>> A;
set<int> checked;


void solve() {
  int N; cin >> N;
  A.reserve(N);
  REP0(i, N) {
      queue<int> Q;
      REP0(j, N-1) {
        int A_ij; cin >> A_ij;
        Q.push(A_ij);   
      }
      A.push_back(Q);
  }
  int ans=-1;
  bool ALLdone=false;

  while (not ALLdone){
    int battle=0;
    ALLdone=true;
    REP0(i, N) {  // 一日分のチェック
        if (A[i].empty() or EXIST(checked, i)) continue;
        if (not A[i].empty()) ALLdone = false;
        int obj_i = A[i].front()-1;
        if (EXIST(checked, obj_i)) continue;
        int obj = A[ obj_i ].front() -1;
        if (obj == i) {
         //   cout << "day:" << ans << " " << i << " vs " << obj_i << endl;
            battle++;
            A[i].pop();
            A[obj_i].pop();
            checked.insert(i);
            checked.insert(obj_i);
        }
        if (not A[i].empty()) ALLdone = false;
    }
    if (battle == 0 and not ALLdone) { // 試合が一回も行えなかった
        cout << -1 << endl;
        return;
    }
    checked.clear();
    ans++;
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