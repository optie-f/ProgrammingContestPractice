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

// i 番目から出発したときの最長経路
int dp[TENS(5)];
int deg_o[TENS(5)];
int visited[TENS(5)];
vector<int> A[TENS(5)];
int N, M;

int dfs(int v)
{
    if (visited[v])
        return dp[v];

    visited[v] = 1;
    int ans = 0;

    for (auto j : A[v])
    {
        ans = max(ans, dfs(j) + 1);
    }
    return dp[v] = ans;
}

void solve()
{
    cin >> N;
    cin >> M;
    // A[i]...iに向かう頂点の配列

    REP0(i, M)
    {
        int x, y;
        cin >> x >> y;
        A[y].push_back(x);
        deg_o[x]++;
    }

    int ans = 0;

    REP1(i, N)
    {
        if (deg_o[i] == 0) // 終点
        {
            ans = max(ans, dfs(i));
            //         queue<int> S;
            //         S.push(i);
            //         while (S.size())
            //         {
            //             int v = S.front();
            //             S.pop();

            //             for (auto j : A[v])
            //             { // j : vへ向かう頂点
            //                 S.push(j);
            //                 dp[j] = max(dp[j], dp[v] + 1);
            //                 ans = max(ans, dp[j]);
            //             }
            //         }
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