#include <vector>
// Range Min Query として実装
// 二分木の各ノードに区間としての計算結果を持つ
struct SegTree
{
    // 一次元配列に完全二分木
    std::vector<int> data;
    // 単位元 (min なら inf)
    int e = 1e9;
    int N = 1;

    SegTree(int size)
    {
        while (N < size)
            N <<= 1;
        data.resize(N, e);
    }

    void update(int i, int x)
    {
        i += N - 1; // 要素 i の木中ノード番号
        data[i] = x;
        while (i > 0)
        {
            i = (i - 1) / 2; // 親ノード番号
            data[i] = std::min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    int query(int q_l, int q_r)
    { // [q_l, q_r) に対するクエリの処理
        return _query(q_l, q_r, 0, 0, N);
    }

private:
    int _query(int q_l, int q_r, int k, int k_l, int k_r)
    {
        if (k_r <= q_l || q_r <= k_l)
            return e; // 交差しない
        if (q_l <= k_l && k_r <= q_r)
            return data[k]; // 完全に含む→受け止める
        else
        {
            int vl = _query(q_l, q_r, k * 2 + 1, k_l, (k_l + k_r) / 2);
            int vr = _query(q_l, q_r, k * 2 + 2, (k_l + k_r) / 2, k_r);
            return std::min(vl, vr);
        }
    }
};