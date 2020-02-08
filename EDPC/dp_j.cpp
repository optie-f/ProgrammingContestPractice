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

// dp[c1][c2][c3] : 寿司 i 個の皿が ci 個あるときの操作回数の期待値
double dp[301][301][301];
// = 1 + dp[c1-1][c2][c3] * c1/N
//     + dp[c1+1][c2-1][c3] * c2/N
//     + dp[c1][c2+1][c3-1] * c3/N
//     + dp[c1][c2][c3] * (N-(c1+c2+c3))/N
bool flag[301][301][301];

double rec(int N, int c1, int c2, int c3)
{
    if (flag[c1][c2][c3])
        return dp[c1][c2][c3];
    if (c1 + c2 + c3 == 0)
        return 0.0;

    flag[c1][c2][c3] = true;

    double prob_no_chosen = (double)(N - (c1 + c2 + c3)) / N;
    double coef = (1.0 - prob_no_chosen);
    double e = 1.0;

    if (c1 > 0)
        e += rec(N, c1 - 1, c2, c3) * (c1 / (double)N);
    if (c2 > 0)
        e += rec(N, c1 + 1, c2 - 1, c3) * (c2 / (double)N);
    if (c3 > 0)
        e += rec(N, c1, c2 + 1, c3 - 1) * (c3 / (double)N);

    dp[c1][c2][c3] = e / coef;

    return dp[c1][c2][c3];
}

void solve()
{
    int N;
    cin >> N;
    vector<double> a(N);
    int cnt[3] = {0, 0, 0};

    REP0(i, N)
    {
        int a;
        cin >> a;
        cnt[a - 1]++;
    }

    cout << rec(N, cnt[0], cnt[1], cnt[2]) << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}