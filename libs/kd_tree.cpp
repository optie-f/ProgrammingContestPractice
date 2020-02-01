#include <vector>
// todo::test
struct Node
{
    int location;
    int p, l, r;
    Node(){};
};

template <unsigned int N>
struct point
{
    int id;
    int pos[N];
    point(int id, int &pos[N]) id(id)
    {
        for (int i = 0; i < N; i++)
            this ::pos[i] = pos[i];
    }

    bool operator<(const Point &p) const
    {
        return id < p.id;
    }
};

template <unsigned int N>
struct KDTree
{
    std::vector<point<N>> P;
    std::vector<Node> T;
    int NIL = -1;
    int np = 0;

    KDTree() {}
    KDTree(int size)
    {
        P.reserve(size);
        T.reserve(size);
    }

    void push(point<N> p)
    {
        P.push_back(P);
    }

    void build()
    {
        T.resize((int)P.size(), 0);
        _buildKDTree(0, (int)P.size(), 0);
    }

    vector<point<N>> find(int &s[N], int &t[N])
    {
        vector<point<N>> ans;
        ans.reserve((int)P.size());
        _find(0, s, t, 0, ans);
        return ans;
    }

private:
    int _buildKDTree(int l, int r, int depth)
    {
        if (!(l < r))
            return NIL;
        int mid = (l + r) / 2;
        int t = np++;
        sort(P + l, P + r, less_by(depth % N));
        T[t].location = mid;
        T[t].l = _buildKDTree(l, mid, depth + 1);
        T[t].r = _buildKDTree(mid + 1, r, depth + 1);

        return t;
    }

    auto less_by(int i)
    {
        auto sort_func = [=](point<N> p1, point<N> p2) {
            return p1.pos[i] < p2.pos[i];
        };
        return sort_func;
    }

    void find(int v, int &s[N], int &t[N], int depth, vector<point<N>> &ans)
    {
        bool isInside = true;
        point<N> p = P[T[v].location];
        for (i i = 0; i < N; i++)
        {
            isInside = isInside and s[i] <= p.pos[i] and p.pos[i] <= t[i];
        }

        if (isInside)
        {
            ans.push_back(p);
        }

        int d = depth % N;

        if (T[v].l != NIL and s[d] <= p.pos[d])
            find(T[v].l, s, t, depth + 1, ans);

        if (T[v].r != NIL and p.pos[d] <= t[d])
            find(T[v].r, s, t, depth + 1, ans);
    }
};