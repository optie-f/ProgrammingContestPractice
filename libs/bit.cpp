#include <bits/stdc++.h>
using namespace std;

template <int N> bitset<N> bitset_count(bitset<N> bit)
{
    int cnt = 0;
    for (int i = 0; i < N; i++) cnt += bit[i];
    return cnt;
}