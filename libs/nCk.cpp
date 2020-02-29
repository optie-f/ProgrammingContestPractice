template <int MOD> struct intmod
{  // modified from http://drken1215.hatenablog.com/entry/2020/02/09/225000
    long long val;
    constexpr intmod(long long v = 0) noexcept : val(v % MOD)
    {
        if (val < 0)
            val += MOD;
    }
    constexpr int getmod()
    {
        return MOD;
    }
    constexpr intmod operator-() const noexcept
    {
        return val ? MOD - val : 0;
    }
    constexpr intmod operator+(const intmod &r) const noexcept
    {
        return intmod(*this) += r;
    }
    constexpr intmod operator-(const intmod &r) const noexcept
    {
        return intmod(*this) -= r;
    }
    constexpr intmod operator*(const intmod &r) const noexcept
    {
        return intmod(*this) *= r;
    }
    constexpr intmod operator/(const intmod &r) const noexcept
    {
        return intmod(*this) /= r;
    }
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
        t      = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }
};

template <class T> struct BiCoef
{  // modified from http://drken1215.hatenablog.com/entry/2020/02/09/225000
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef()
    {
    }
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1)
    {
        init(n);
    }
    constexpr void init(int n) noexcept
    {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        int MOD = fact_[0].getmod();
        for (int i = 2; i < n; i++)
        {
            fact_[i] = fact_[i - 1] * i;
            inv_[i]  = -inv_[MOD % i] * (MOD / i);
            finv_[i] = finv_[i - 1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept
    {
        if (n < k || n < 0 || k < 0)
            return 0;
        return fact_[n] * finv_[k] * finv_[n - k];
    }
    constexpr T H(int n, int k) const noexcept
    {
        return com(n + k - 1, k);
    }
    constexpr T fact(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return finv_[n];
    }
};

const int mod = int(1e9) + 7;
typedef intmod<mod> mint;
typedef BiCoef<mint> BC;
BC bc;