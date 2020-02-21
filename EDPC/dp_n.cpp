#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF   = 1e18;
#define TENS(n) int(1e##n + n)

// [i, j) における最適値
LL dp[402][402];
LL cum[402];
bool flg[402][402];

LL rec(int l, int r)
{
    if (abs(l - r) == 1 or flg[l][r])
        return dp[l][r];

    flg[l][r] = true;

    LL ans = LLINF;
    for (int i = l + 1; i < r; i++)
    {
        ans = min(ans, rec(l, i) + rec(i, r));
    } // [l, r)のどこで合成しても、この回でかかるコストは範囲のスライムの総和
    ans += cum[r - 1] - cum[l - 1];
    return dp[l][r] = ans;
}

void solve()
{
    int N;
    cin >> N;
    REP0 (i, N)
    {
        cin >> cum[i];
        if (i)
            cum[i] += cum[i - 1];
    }

    cout << rec(0, N) << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}