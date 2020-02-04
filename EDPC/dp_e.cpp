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
const int max_value = TENS(3) * 100;

// dp[i][j] : i番目までから価値がjとなるよう選んだときの重さの最小値
long long dp[101][max_value + 1];

void solve()
{

    unsigned int N, W;
    cin >> N >> W;
    vector<int> value(N);
    vector<LL> weight(N);

    REP0(i, N)
    {
        cin >> weight[i] >> value[i];
    }

    REP1(i, max_value)
    {
        dp[0][i] = LLINF;
    }

    dp[0][value[0]] = weight[0];
    int ans = (weight[0] <= W) ? value[0] : 0;

    REP1(i, N - 1)
    {
        dp[i][0] = 0;
        REP1(j, max_value)
        {
            if (0 <= j - value[i])
                dp[i][j] = min(dp[i - 1][j],
                               dp[i - 1][j - value[i]] + weight[i]);
            else
                dp[i][j] = dp[i - 1][j];

            if (dp[i][j] <= W)
                ans = max(ans, j);
        }
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