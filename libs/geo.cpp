#include <bits/stdc++.h>


namespace geo
{
using Real = double;
struct vector2D
{
    Real x;
    Real y;

    vector2D(Real x, Real y) : x(x), y(y){};
    vector2D() : x(0), y(0){};

    vector2D operator+(vector2D p)
    {
        return vector2D(x + p.x, y + p.y);
    };
    vector2D operator-(vector2D p)
    {
        return vector2D(x - p.x, y - p.y);
    };
    vector2D operator*(Real s)
    {
        return vector2D(s * x, s * y);
    };
    vector2D operator/(Real s)
    {
        return vector2D(x / s, y / s);
    };

    friend Real cross(vector2D a, vector2D b)
    {
        return a.x * b.y - a.y * b.x;
    };
    friend Real dot(vector2D a, vector2D b)
    {
        return a.x * b.x + a.y * b.y;
    };
};

Real normL2(vector2D p)
{
    return std::sqrt(dot(p, p));
};

struct segment
{
    vector2D p1;
    vector2D p2;

    segment(vector2D p1, vector2D p2) : p1(p1), p2(p2){};
};

Real distLP(segment l, vector2D p)
{
    return std::abs(cross(l.p2 - l.p1, p - l.p1) / normL2(l.p2 - l.p1));
}

Real distSP(segment s, vector2D p)
{
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0)
        return normL2(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0)
        return normL2(p - s.p2);
    return distLP(s, p);
}

}  // namespace geo