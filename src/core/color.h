#include "tuple.h"

class Color : public Tuple {
    public:
        Color() {};
        Color(float r, float g, float b);

        float red() const { return this->x(); }
        float green() const { return this->y(); }
        float blue() const { return this->z(); }
};

Color operator* (const Color lhs, const Color rhs);
Color operator* (const Color c, const float scalar);
Color operator+ (const Color lhs, const Color rhs);
Color operator- (const Color lhs, const Color rhs);

