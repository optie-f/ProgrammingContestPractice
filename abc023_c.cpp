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

int r[100001];
int c[100001];
// i 行/列 目の飴の個数
int agg_r[100001];
int agg_c[100001];
// 飴が i 個ある行/列
// cnt_r[i] * cnt_c[j] が発生するのでLLとしておく
LL cnt_r[100001];
LL cnt_c[100001];

void solve()
{
    LL R, C, K;
    cin >> R >> C >> K;
    int N;
    cin >> N;

    REP0(i, N)
    {
        cin >> r[i] >> c[i];
        agg_r[r[i]]++;
        agg_c[c[i]]++;
    }

    REP1(i, R)
    {
        cnt_r[agg_r[i]]++;
    }

    REP1(i, C)
    {
        cnt_c[agg_c[i]]++;
    }

    LL ans = 0;

    for (int i = 0; i <= K; i++)
        ans += cnt_r[i] * cnt_c[K - i];

    REP0(i, N)
    {
        if (agg_r[r[i]] + agg_c[c[i]] == K)
            ans--;
        else if (agg_r[r[i]] + agg_c[c[i]] == K + 1)
            ans++;
    }

    std::cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}