template <int MOD>
struct intmod
{ // modified from http://drken1215.hatenablog.com/entry/2020/02/09/225000
    long long val;
    constexpr intmod(long long v = 0) noexcept : val(v % MOD)
    {
        if (val < 0)
            val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr intmod operator-() const noexcept
    {
        return val ? MOD - val : 0;
    }
    constexpr intmod operator+(const intmod &r) const noexcept { return intmod(*this) += r; }
    constexpr intmod operator-(const intmod &r) const noexcept { return intmod(*this) -= r; }
    constexpr intmod operator*(const intmod &r) const noexcept { return intmod(*this) *= r; }
    constexpr intmod operator/(const intmod &r) const noexcept { return intmod(*this) /= r; }
    constexpr intmod &operator+=(const intmod &r) noexcept
    {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr intmod &operator-=(const intmod &r) noexcept
    {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr intmod &operator*=(const intmod &r) noexcept
    {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr intmod &operator/=(const intmod &r) noexcept
    {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b)
        {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr bool operator==(const intmod &r) const noexcept
    {
        return this->val == r.val;
    }
    constexpr bool operator!=(const intmod &r) const noexcept
    {
        return this->val != r.val;
    }
    friend constexpr ostream &operator<<(ostream &os, const intmod<MOD> &x) noexcept
    {
        return os << x.val;
    }
    friend constexpr intmod<MOD> modpow(const intmod<MOD> &a, long long n) noexcept
    {
        if (n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }
};
const int mod = int(1e9) + 7;
typedef intmod<mod> mint;