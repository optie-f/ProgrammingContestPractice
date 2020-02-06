#include <cmath>

long long modpow(long long a, long long b, long long mod)
{// a^b % mod を log(b) で計算する
    if (b == 0)
        return 1;

    if (b % 2 == 0)
    {
        long long d = modpow(a, b / 2, mod) % mod;
        return (d * d) % mod;
    }
    else if (b % 2 == 1)
    {
        return (a * modpow(a, b - 1, mod)) % mod;
    }
}


long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b)
{ // bracket to avoid overflow
    return a * (b / gcd(a, b));
}

bool is_prime(long long N)
{
    if (N <= 1)
        return false;
    if (N == 2)
        return true;
    long long ub = std::sqrt(N);
    if (ub * ub == N)
        return false;
    for (long long i = 3; i <= ub; i += 2)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}

long long prime_num(long long N, long long p)
{
    long long cnt = 0;
    while (N % p == 0 and N > 1)
    {
        N /= p;
        cnt++;
    }
    return cnt;
}