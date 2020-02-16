#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF   = 1e18;
#define pow10(n) int(1e##n + n)

// dp[i][j] 下から i 桁目まで決めて,
// 繰り下がりが j:0/1 のときの支払う紙幣の合計最小値
int dp[1'000'002][2];

void solve()
{
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    S += '0';
    int N = S.length();

    REP0 (i, N + 1)
        REP0 (j, 2)
            dp[i][j] = INTINF;
    dp[0][0] = 0;

    REP0 (i, N)
    {
        int s = S[i] - '0';
        REP0 (j, 2)
        {
            // その桁が前の桁の引き算によって繰り下がっている j=1 とき, その桁では 1 枚多く払う必要がある.
            // また, ある桁での払い方は「s 枚ピッタリ払う（=繰り下がり発生させず）」か
            //「0 にして次の桁にまかせる（=繰り下がって,お釣りが 10-s 枚発生する）」かの二通りしかない
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + s + j);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + 10 - (s + j));
        }
    }

    cout << dp[N][0] << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
