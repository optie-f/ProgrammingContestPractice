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

// dp[i][k] : 手番が i =(0/1:先手/後手)で石が残り k 個のとき先手が勝つかどうか
bool dp[2][TENS(5)];
bool flag[TENS(5)];
int a[101];
int N;
int min_a = INTINF;

bool dfs(int turn, int k)
{
    if (flag[k])
        return dp[turn][k];

    flag[k] = true;

    if (k < min_a)
    { // kが減らせなくなったとき, turn が 1=後手 であれば先手の勝ち
        dp[turn][k] = (turn == 1);
        dp[1 - turn][k] = !dp[turn][k];
        return dp[turn][k];
    }

    if (turn == 0)
    { // 残り k の先手番において、先手が勝利するような a[i] の選び方がひとつでもあれば、先手は勝てる
        bool win = false;
        REP0(i, N)
        {
            if (0 <= k - a[i])
                win = win or dfs(1 - turn, k - a[i]);
        }
        dp[turn][k] = win;
        dp[1 - turn][k] = !dp[turn][k];
        return dp[turn][k];
    }
    else
    { // 残り k の後手番において、先手が負けるようなa[i]の選び方がひとつでもあれば、先手は負ける
        bool win = true;
        REP0(i, N)
        {
            if (0 <= k - a[i])
                win = win and dfs(1 - turn, k - a[i]);
        }
        dp[turn][k] = win;
        dp[1 - turn][k] = !dp[turn][k];
        return dp[turn][k];
    }
}

void solve()
{
    cin >> N;
    int K;
    cin >> K;

    REP0(i, N)
    {
        cin >> a[i];
        min_a = min(a[i], min_a);
    }

    cout << (dfs(0, K) ? "First" : "Second") << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}