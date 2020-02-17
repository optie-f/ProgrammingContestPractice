#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF   = LL(1e18) + LL(1e17);
#define pow10(n) int(1e##n + n)

void solve()
{
    int N;
    cin >> N;
    LL K;
    cin >> K;
    vector<LL> A(N);
    REP0 (i, N)
        cin >> A[i];
    sort(A.begin(), A.end());

    // x -> 積が x 以下であるようなペアは K 未満であるかどうか
    auto isok = [&](LL x) {
        LL total = 0;
        REP0 (i, N)
        {  // A[i]とのペアのうち, 積がKを超えない最大の値を見つける
            if (A[i] < 0)
            {  // A[i] が負だと, 後ろから何番目かまでが条件を満たす
                int ng = -1, ok = N;
                while (abs(ng - ok) > 1)
                {
                    int c = (ng + ok) / 2;
                    if (A[c] * A[i] < x)
                        ok = c;
                    else
                        ng = c;
                }
                total += N - (ng + 1);
            }
            else
            {  // A[i]が正ならば, 前から何番目かまでが条件を満たす
                int ok = -1, ng = N;
                while (abs(ng - ok) > 1)
                {
                    int c = (ng + ok) / 2;
                    if (A[c] * A[i] < x)
                        ok = c;
                    else
                        ng = c;
                }
                total += ok + 1;
            }
            // この計算は重複をカウントしているので, あれば外す
            if (A[i] * A[i] < x)
                total--;
        }
        // 同じペアの逆もカウントしているので, それも外す
        total /= 2;
        return total < K;
    };

    LL ok = -LLINF, ng = LLINF;

    while (abs(ng - ok) > 1)
    {
        LL x = (ok + ng) / 2;
        if (isok(x))
            ok = x;
        else
            ng = x;
    }
    cout << ok << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
