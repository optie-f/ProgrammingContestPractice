#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;
const int dg5 = 1e5;

// dp[j][i] : i 日目に j を選ぶとしたときの最大幸福度
LL dp[3][dg5 + 1];
LL abc[3][dg5 + 1];

void solve()
{
    int N;
    cin >> N;
    REP0(i, N)
    {
        cin >> abc[0][i] >> abc[1][i] >> abc[2][i];
    }

    REP0(i, 3)
    {
        dp[i][0] = abc[i][0];
    }

    REP1(i, N - 1)
    {
        REP0(j, 3)
        {
            dp[j][i] = max(dp[(j + 1) % 3][i - 1] + abc[j][i],
                           dp[(j + 2) % 3][i - 1] + abc[j][i]);
        }
    }

    LL ans = 0;
    REP0(i, 3)
    {
        ans = max(ans, dp[i][N - 1]);
    }

    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}