#include <vector>
// 頂点をインデックスで管理する
struct UnionFind
{
    std::vector<int> rank, p, cnt;

    UnionFind(){};
    UnionFind(int size)
    {
        init(size);
    }

    void init(int size)
    {
        rank.resize(size, 0);
        p.resize(size, 0);
        cnt.resize(size, 0);
        for (int i = 0; i < size; i++) makeSet(i);
    }

    void makeSet(int x)
    {
        p[x] = x;
        rank[x] = 0;
        cnt[x] = 1;
    }

    bool same(int x, int y)
    {
        return findSet(x) == findSet(y);
    }

    void unite(int x, int y)
    {
        if (same(x, y))
            return;
        link(findSet(x), findSet(y));
    }

    void link(int x, int y)
    {
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
    {
        if (x != p[x])
        {
            p[x] = findSet(p[x]);
        }
        return p[x];
    }

    int setSize(int x)
    {
        return cnt[findSet(x)];
    }
};