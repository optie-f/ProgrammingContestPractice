#include <vector>
template <typename Monoid> struct SegTree
{
    typedef function<Monoid(Monoid, Monoid)> F;
    std::vector<Monoid> data;  // 0-indexed 配列に完全二分木
    const Monoid e;            // 単位元
    const F f;
    int N = 1;

    SegTree(int size, const F f, const Monoid &e) : f(f), e(e)
    {
        while (N < size) N <<= 1;
        data.resize(2 * N - 1, e);  // 要素数 n => ノード数 2*n - 1
    }

    void update(int i, Monoid x)
    {
        i += N - 1;  // 要素 i の木中ノード番号
        data[i] = x;
        while (i > 0)
        {
            i       = (i - 1) / 2;  // 親ノード番号
            data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    Monoid query(int q_l, int q_r)
    {  // [q_l, q_r) に対するクエリの処理
        return _query(q_l, q_r, 0, 0, N);
    }

   private:
    Monoid _query(int q_l, int q_r, int k, int k_l, int k_r)
    {  // ノード k : 区間は [k_l, k_r) について
        if (k_r <= q_l || q_r <= k_l)
            return e;  // 交差しない
        if (q_l <= k_l && k_r <= q_r)
            return data[k];  // 完全に含む→受け止める
        else
        {
            Monoid vl = _query(q_l, q_r, k * 2 + 1, k_l, (k_l + k_r) / 2);
            Monoid vr = _query(q_l, q_r, k * 2 + 2, (k_l + k_r) / 2, k_r);
            return f(vl, vr);
        }
    }
};