#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF   = 1e18;
#define pow10(n) int(1e##n + n)

void solve()
{
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<LL> A_n, A_0, A_p;
    REP0 (i, N)
    {
        LL a;
        cin >> a;
        if (a > 0)
            A_p.push_back(a);
        else if (a < 0)
            A_n.push_back(-a);
        else
            A_0.push_back(a);
    }

    sort(A_p.begin(), A_p.end());
    sort(A_n.begin(), A_n.end());

    int n_p = A_p.size();
    int n_0 = A_0.size();
    int n_n = A_n.size();

    if (K <= n_p * n_n)
    {
        int ptr=0;
        for (int i=n_n-1; i>=0; i--)
        {
            if (ptr + n_p<K)
            {
                ptr += n_p; continue;
            }
            else
            {
                cout << A_n[i] * A_p[] << endl;
            }
        }
    }
    else if (K <= n_p * n_n + n_0 * (n_0 - 1) / 2 + n_0 * (n_n + n_p))
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        int ptr = n_p * n_n + n_0 * (n_0 - 1) / 2 + n_0 * (n_n + n_p);
        
    }
    

        LL ptr = 0;

    REP0 (i, N - 1)
    {
        if (ptr + N - (i + 1) < K)
        {  // その段にK番目はない
            ptr += N - (i + 1);
            continue;
        }
        else
        {
            if (A[i] == 0)
            {
                cout << 0 << endl;
                return;
            }
            else if (A[i] > 0)
            {
                int delta = K - ptr;
                cout << A[i] * A[i + delta] << endl;
                return;
            }
            else
            {
                int delta = K - ptr;
                cout << A[i] * A[N - delta] << endl;
                return;
            }
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
