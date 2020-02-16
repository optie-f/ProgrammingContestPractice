#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF   = 1e18;
#define pow10(n) int(1e##n + n)

void solve()
{
    int N;
    cin >> N;
    map<string, int> poll;
    int n_max = 0;
    REP0 (i, N)
    {
        string S;
        cin >> S;
        poll[S]++;
        n_max = max(n_max, poll[S]);
    }

    for (auto p : poll)
    {
        if (p.second == n_max)
        {
            cout << p.first << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
