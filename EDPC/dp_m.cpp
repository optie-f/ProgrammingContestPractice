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
const LL mod = 1e9 + 7;

// i番目までにj個配る方法の数
LL dp[101][TENS(5)];
int N, K;
int a[101];
LL cum[TENS(5)];

void solve()
{
    cin >> N >> K;
    REP1(i, N)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;

    // REP1(i, N)
    // { // i 番目までの子に
    //     REP0(j, K + 1)
    //     { // 飴を j 個配るときの場合の数は
    //         REP0(k, a[i] + 1)
    //         { // i-1 番目までの子に max(0, j-a[i])~j 個 配る配り方の和
    //             if (j >= k)
    //             {
    //                 dp[i][j] += (dp[i - 1][j - k] % mod);
    //                 dp[i][j] %= mod;
    //             }
    //         }
    //     }
    // }

    REP1(i, N)
    {
        // cum[j]: 半開区間累積和 = dp[i-1][j-1] + dp[i-1][j-1] + ... + dp[i-1][0]
        cum[0] = 0;
        REP1(j, K + 1)
        {
            cum[j] = (cum[j - 1] % mod + dp[i - 1][j - 1] % mod) % mod;
            cum[j] %= mod;
        }
        REP0(j, K + 1)
        {
            dp[i][j] += (cum[j + 1] - cum[max(0, j - a[i])] + mod) % mod;
            dp[i][j] %= mod;
        }
    }

    cout << dp[N][K] << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}