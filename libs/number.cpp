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