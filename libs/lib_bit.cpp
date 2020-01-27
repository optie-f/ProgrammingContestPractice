int bit_count (int bit, int N)
{
    int cnt = 0;
    for (int i=0; i<N; i++) if (bit & (1 << i)) cnt++;
    return cnt;
} 