#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;
const int w_max = 1e5;

// dp[i][j] : i番目までの品物から重さ j 以下になるように選んだときの価値の最大値
LL dp[101][w_max + 1];

void solve()
{
    int N;
    cin >> N;
    int W;
    cin >> W;
    vector<int> w(N);
    vector<LL> v(N);
    REP0(i, N)
    {
        cin >> w[i] >> v[i];
    }

    REP0(i, N)
    {
        REP1(j, W)
        {
            if (i == 0)
            {
                dp[0][j] = (w[0] <= j) ? v[0] : 0;
                continue;
            }

            if (0 <= j - w[i])
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N - 1][W] << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}