const int INTINF = 1e9;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n_V;
int flag[500];
int A[500][500];
int d[500];
int prev[500];

void dijkstra()
{
    for (int i = 1; i <= n_V; i++)
    {
        d[i] = INTINF;
        prev[i] = -1;
    }

    while (true)
    {
        int u = 0;
        int mincost = INTINF;
        for (int i = 1; i <= n_V; i++)
        {
            if (flag[i] != BLACK and d[i] < mincost)
            {
                mincost = d[i];
                u = i;
            }
        }

        if (mincost == INTINF or u <= 1)
            break;
        flag[u] = BLACK;

        for (int i = 1; i <= n_V; i++)
        {
            if (flag[i] != BLACK and (A[u][i] > 0))
                if (d[u] + A[u][i] < d[i])
                {
                    d[i] = d[u] + A[u][i];
                    prev[i] = u;
                    flag[i] = GRAY;
                }
        }
    }
}