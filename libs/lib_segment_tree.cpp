#include <vector>
// Range Min Query として実装
// 二分木の各ノードに区間としての計算結果を持つ
struct SegTree
{
    // 一次元配列に完全二分木
    std::vector<long long> data;
    // 単位元 (min なら inf)
    long long e = (1ll << 31) - 1;
    int N = 1;

    SegTree(int size)
    {
        while (N < size)
            N <<= 1;
        // 要素数 n ではノード数は 2*n - 1
        data.resize(2 * N - 1, e);
    }

    void update(int i, long long x)
    {
        i += N - 1; // 要素 i の木中ノード番号
        data[i] = x;
        while (i > 0)
        {
            i = (i - 1) / 2; // 親ノード番号
            data[i] = std::min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    long long query(int q_l, int q_r)
    { // [q_l, q_r) に対するクエリの処理
        return _query(q_l, q_r, 0, 0, N);
    }

private:
    long long _query(int q_l, int q_r, int k, int k_l, int k_r)
    { // ノード k : 区間は [k_l, k_r) について
        if (k_r <= q_l || q_r <= k_l)
            return e; // 交差しない
        if (q_l <= k_l && k_r <= q_r)
            return data[k]; // 完全に含む→受け止める
        else
        {
            long long vl = _query(q_l, q_r, k * 2 + 1, k_l, (k_l + k_r) / 2);
            long long vr = _query(q_l, q_r, k * 2 + 2, (k_l + k_r) / 2, k_r);
            return std::min(vl, vr);
        }
    }
};