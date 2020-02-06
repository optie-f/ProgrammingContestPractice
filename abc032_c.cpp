#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;
#define pow10(n) int(1e##n + n)

void solve()
{
    int N;
    cin >> N;
    LL K;
    cin >> K;
    vector<LL> s(N);
    REP0(i, N)
    {
        cin >> s[i];
        if (s[i] == 0)
        {
            cout << N << endl;
            return;
        }
    }

    int ans = 0;
    int l = 0;
    int r = 0;
    LL prod = 1;

    while (l < N)
    {
        while (r < N)
        {
            if (prod * s[r] <= K)
            {
                prod *= s[r];
                ans = max(ans, r + 1 - l);
                r++;
            }
            else
                break;
        }
        if (l != r)
            prod /= s[l];
        l++;
        r = max(r, l);
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