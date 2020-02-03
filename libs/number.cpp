#include <cmath>
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
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