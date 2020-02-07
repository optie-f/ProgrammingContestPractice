#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;
#define TENS(n) int(1e##n + n)

// dp[i][j] : i番目までにj回表が出る
double dp[3000][3000];
// とおくと,
// dp[i][j] = dp[i-1][j] + dp[i-1][j-1] * p_i

void solve()
{
    int N;
    cin >> N;
    vector<double> p(N + 1);
    REP1(i, N)
    {
        cin >> p[i];
    }

    dp[1][0] = (1 - p[1]);
    dp[1][1] = p[1];

    FOR(i, 2, N+1)
    {
        dp[i][0] = dp[i - 1][0] * (1 - p[i]);
        dp[i][i] = dp[i - 1][i - 1] * p[i];
        REP1(j, i-1)
        {
            dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];
        }
    }

    double ans = 0;
    FOR(i, N / 2 + 1, N + 1)
    {
        ans += dp[N][i];
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