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

// Sのi-1文字目までとTのj-1文字目までのLCS
int dp[3001][3001];

void solve()
{
    string s, t;
    cin >> s >> t;

    int S = s.length();
    int T = t.length();

    REP1(i, S)
    {
        REP1(j, T)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    int len = dp[S][T];
    string result = "";
    int i = S - 1;
    int j = T - 1;
    while (len)
    {
        if (s[i] == t[j])
        {
            result = s[i] + result;
            i--; j--; len--;
        }
        else if (dp[i+1][j+1]==dp[i+1][j])
            j--;
        else
            i--;
    }

    cout << result << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}