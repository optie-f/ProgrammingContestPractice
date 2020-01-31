int bit_count(int bit)
{
    int cnt = 0;
    for (int i = 0; (1 << i) <= bit; i++)
        if (bit & (1 << i))
            cnt++;
    return cnt;
}