#include <cmath>

template <typename number> number numpow(number a, long long b)
{  // a^b
    if (b == 0)
        return 1;

    if (b % 2 == 0)
    {
        number d = numpow(a, b / 2);
        return (d * d);
    }

    return (a * numpow(a, b - 1));
}

long long modpow(long long a, long long b, long long mod)
{  // a^b % mod を log(b) で計算する
    if (b == 0)
        return 1;

    if (b % 2 == 0)
    {
        long long d = modpow(a, b / 2, mod) % mod;
        return (d * d) % mod;
    }

    return (a * modpow(a, b - 1, mod)) % mod;
}

long long GCD(long long a, long long b)
{
    return b ? GCD(b, a % b) : a;
}

long long LCM(long long a, long long b)
{  // bracket to avoid overflow
    return a * (b / GCD(a, b));
}

bool is_prime(long long N)
{
    if (N <= 1)
        return false;
    if (N == 2)
        return true;
    if (N % 2 == 0)
        return false;
    for (long long i = 3; i * i <= N; i += 2)
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