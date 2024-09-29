#include "color.h"

Color::Color(float r, float g, float b) : Tuple(r, g, b, 0) {};

Color operator+(const Color lhs, const Color rhs)
{
    return Color(
        lhs.red() + rhs.red(),
        lhs.green() + rhs.green(),
        lhs.blue() + rhs.blue()
    );
}

Color operator-(const Color lhs, const Color rhs)
{
    return Color(
        lhs.red() - rhs.red(),
        lhs.green() - rhs.green(),
        lhs.blue() - rhs.blue()
    );
}

Color operator*(const Color c, const float scalar)
{
    return Color(
        c.red() * scalar,
        c.green() * scalar,
        c.blue() * scalar
    );
}

Color operator*(const Color lhs, const Color rhs)
{
    return Color(
        lhs.red() * rhs.red(),
        lhs.green() * rhs.green(),
        lhs.blue() * rhs.blue()
    );
}
