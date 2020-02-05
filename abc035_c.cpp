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

int board[200'0001];

void solve()
{
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    REP0(i, Q)
    {
        int l, r;
        cin >> l >> r;
        board[l]++;
        board[r + 1]--;
    }

    REP1(i, N)
    {
        board[i] += board[i - 1];
        cout << board[i] % 2;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}