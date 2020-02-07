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

char a[1002][1002];
LL dp[1002][1002];
LL mod = 1e9 + 7;

struct pos
{
    int x;
    int y;
};

void solve()
{
    int H;
    cin >> H;
    int W;
    cin >> W;

    REP1(i, H)
    {
        REP1(j, W)
        {
            cin >> a[i][j];
        }
    }
    dp[1][1] = 1;

    REP1(y, H)
    {
        REP1(x, W)
        {
            if (a[y - 1][x] == '.')
            {
                dp[y][x] += (dp[y - 1][x] % mod);
                dp[y][x] %= mod;
            }

            if (a[y][x - 1] == '.')
            {
                dp[y][x] += (dp[y][x - 1] % mod);
                dp[y][x] %= mod;
            }
        }
    }

    // queue<pos> Q;
    // Q.push(pos{1, 1});
    // while (Q.size())
    // {
    //     pos now = Q.front();
    //     Q.pop();

    //     if (a[now.y - 1][now.x] == '.')
    //     {
    //         dp[now.y][now.x] += (dp[now.y - 1][now.x] % mod);
    //         dp[now.y][now.x] %= mod;
    //     }

    //     if (a[now.y][now.x - 1] == '.')
    //     {
    //         dp[now.y][now.x] += (dp[now.y][now.x - 1] % mod);
    //         dp[now.y][now.x] %= mod;
    //     }
    //     if (a[now.y + 1][now.x] == '.')
    //         Q.push(pos{now.y + 1, now.x});
    //     if (a[now.y][now.x + 1] == '.')
    //         Q.push(pos{now.y, now.x + 1});
    // }

    cout << dp[H][W] << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}