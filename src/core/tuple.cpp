#include "Illumin8/math.h"
#include "tuple.h"
#include <cmath>

Tuple::Tuple(float x, float y, float z, float w)
{
    x_ = x;
    y_ = y;
    z_ = z;
    w_ = w;
};

float Tuple::magnitude() const
{
    return( std::sqrt(
        this->x() * this->x() +
        this->y() * this->y() +
        this->z() * this->z() +
        this->w() * this->w()
    ));
}

Tuple Tuple::normalize() const
{
    float magnitude = this->magnitude();
    return Tuple(
        this->x() / magnitude,
        this->y() / magnitude,
        this->z() / magnitude,
        this->w() / magnitude
    );
}

float Tuple::dot(Tuple tup) const
{
    return (
        this->x() * tup.x() +
        this->y() * tup.y() +
        this->z() * tup.z() +
        this->w() * tup.w()
    );
}

Tuple Tuple::cross(Tuple tup) const
{
    return Vector(
        this->y() * tup.z() - this->z() * tup.y(),
        this->z() * tup.x() - this->x() * tup.z(),
        this->x() * tup.y() - this->y() * tup.x()
    );
}

bool Tuple::isPoint() const
{
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

Tuple operator-(const Tuple lhs, const Tuple rhs)
{
    return Tuple(
        lhs.x() - rhs.x(),
        lhs.y() - rhs.y(),
        lhs.z() - rhs.z(),
        lhs.w() - rhs.w()
    );
}

Tuple operator-(const Tuple neg)
{
    return Tuple (
        - neg.x(),
        - neg.y(),
        - neg.z(),
        - neg.w()
    );
}

Tuple operator*(const Tuple tup, float alpha)
{
    return Tuple(
        alpha * tup.x(), 
        alpha * tup.y(), 
        alpha * tup.z(), 
        alpha * tup.w()
    );
}

Tuple operator/(const Tuple tup, float alpha)
{
    return Tuple(
        tup.x() / alpha, 
        tup.y() / alpha, 
        tup.z() / alpha, 
        tup.w() / alpha
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