#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;
const int dg5 = 1e5;
int dp[dg5 + 1];

void solve()
{
    int N;
    cin >> N;
    vector<int> h(N);
    int K;
    cin >> K;
    REP0(i, N)
    {
        cin >> h[i];

        if (i == 0)
            continue;
        else if (i == 1)
            dp[1] = abs(h[0] - h[1]);
        else
            dp[i] = INTINF;
        for (int j = 1; j <= K and 0 <= i - j; j++)
        {
            dp[i] = min(dp[i - j] + abs(h[i] - h[i - j]), dp[i]);
        }
    }
    cout << dp[N - 1] << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}