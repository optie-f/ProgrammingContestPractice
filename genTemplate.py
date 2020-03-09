import argparse
parser = argparse.ArgumentParser()
parser.add_argument("contest_name")
parser.add_argument("problems")
args = parser.parse_args()


template = """#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9)+1;
const LL LLINF = LL(1e18)+1;
#define pow10(n) int(1e##n + n)

void solve()
{

}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
"""


for suffix in args.problems:
    path = './{0}_{1}.cpp'.format(args.contest_name, suffix)
    with open(path, mode='w') as f:
        f.write(template)
