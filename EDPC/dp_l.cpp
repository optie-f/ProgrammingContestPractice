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

// デックに残る要素が [i,j) だったときのX-Y
LL dp[3001][3001];
LL a[3001];
bool flag[3001][3001];

LL dfs(int turn, int i, int j)
{
    if (flag[i][j] or i == j)
        return dp[i][j];
    flag[i][j] = true;

    LL l = dfs(turn + 1, i + 1, j);
    LL r = dfs(turn + 1, i, j - 1);

    if (turn % 2 == 0)
    {
        l += a[i];
        r += a[j - 1];
        return dp[i][j] = max(l, r);
    }
    else
    {
        l -= a[i];
        r -= a[j - 1];
        return dp[i][j] = min(l, r);
    }
}

void solve()
{
    int N;
    cin >> N;
    REP0(i, N)
    {
        cin >> a[i];
    }

    cout << dfs(0, 0, N) << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}