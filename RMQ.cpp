#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A

struct SegTree
{
    // 一次元配列に完全二分木
    std::vector<LL> data;
    // 単位元 (min なら inf)
    LL e = (1ll << 31) - 1;
    int N = 1;

    SegTree(int size)
    {
        while (N <= size)
            N <<= 1;
        data.resize(N, e);
    }

    void update(int i, LL x)
    {
        i += N - 1; // 要素 i の木中ノード番号
        data[i] = x;
        while (i > 0)
        {
            i = (i - 1) / 2; // 親ノード番号
            data[i] = std::min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    LL query(int q_l, int q_r)
    { // [q_l, q_r) に対するクエリの処理
        return _query(q_l, q_r, 0, 0, N);
    }

private:
    LL _query(int q_l, int q_r, int k, int k_l, int k_r)
    { // ノード k : 区間は [k_l, k_r) について
        if (k_r <= q_l || q_r <= k_l)
            return e; // 交差しない
        if (q_l <= k_l && k_r <= q_r)
            return data[k]; // 完全に含む→受け止める
        else
        {
            LL vl = _query(q_l, q_r, k * 2 + 1, k_l, (k_l + k_r) / 2);
            LL vr = _query(q_l, q_r, k * 2 + 2, (k_l + k_r) / 2, k_r);
            return std::min(vl, vr);
        }
    }
};

void solve()
{
    int N;
    cin >> N;
    int Q;
    cin >> Q;

    SegTree segtree(N);

    REP0(i, Q)
    {
        int com;
        cin >> com;
        int x, y;
        cin >> x >> y;

        REP0(i, segtree.N)
        {
            cout << segtree.data[i] << " ";
        }
        cout << endl;

        switch (com)
        {
        case 0:
            segtree.update(x, y);
            break;

        case 1:
            cout << segtree.query(x, y + 1) << endl;
            break;
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