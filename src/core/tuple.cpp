#include "Illumin8/math.h"
#include "tuple.h"

Tuple::Tuple(float x, float y, float z, float w) {
    x_ = x;
    y_ = y;
    z_ = z;
    w_ = w;
};

bool Tuple::isPoint() const {
    return 1.0 == w_;
}

bool Tuple::isVector() const {
    return 0.0 == w_;
}

bool operator==(const Tuple lhs, const Tuple rhs)
{
    return epsilon_eq(lhs.x(), rhs.x()) &&
        epsilon_eq(lhs.y(), rhs.y()) &&
        epsilon_eq(lhs.z(), rhs.z()) &&
        epsilon_eq(lhs.w(), rhs.w());
}

Tuple operator+(const Tuple lhs, const Tuple rhs)
{
    return Tuple(
        lhs.x() + rhs.x(),
        lhs.y() + rhs.y(),
        lhs.z() + rhs.z(),
        lhs.w() + rhs.w()
    );
}

Tuple Point(float x, float y, float z)
{
    return Tuple(x, y , z, 1.0);
}

Tuple Vector(float x, float y, float z)
{
    return Tuple(x, y , z, 0.0);
}