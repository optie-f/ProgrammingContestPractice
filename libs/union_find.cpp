#include <vector>
// 頂点をインデックスで管理する
struct UnionFind
{
    std::vector<int> rank;  // 木の高さ
    std::vector<int> p;     // 頂点 i の親, root であれば i == p[i]
    std::vector<int> cnt;   // 頂点 i を root とする連結成分の要素数
    int connected;          // 異なる連結成分の個数

    UnionFind(){};
    UnionFind(int size)
    {
        init(size);
    }

    void init(int size)
    {
        connected = size;
        rank.resize(size, 0);
        p.resize(size, 0);
        cnt.resize(size, 0);
        for (int i = 0; i < size; i++) makeSet(i);
    }

    void makeSet(int x)
    {  // 頂点 x からなる単一連結成分
        p[x] = x;
        rank[x] = 0;
        cnt[x] = 1;
    }

    bool same(int x, int y)
    {  // 頂点 x,y の属する連結成分の root が同一ならば, x, y は同じ連結成分
        return findSet(x) == findSet(y);
    }

    void unite(int x, int y)
    {  // 頂点 x, y が異なる連結成分のとき、これらを併合
        if (same(x, y))
            return;
        link(findSet(x), findSet(y));
    }

    void link(int x, int y)
    {  // 頂点 x, y が異なる連結成分との仮定のもと、併合
        connected--;
        if (rank[x] > rank[y])
        {
            p[y] = x;
            cnt[x] += cnt[y];
        }
        else
        {
            p[x] = y;
            cnt[y] += cnt[x];
            rank[y] += (rank[x] == rank[y]);
        }
    }

    int findSet(int x)
    {  // 頂点 x が属する連結成分の root
        if (x != p[x])
        {
            p[x] = findSet(p[x]);
        }
        return p[x];
    }

    int setSize(int x)
    {  // 頂点 x が属する連結成分の頂点数
        return cnt[findSet(x)];
    }
};