#include "tuple.h"

class Color : public Tuple {
    public:
        Color() {};
        Color(float r, float g, float b);

        float red() const { return this->x(); }
        float green() const { return this->y(); }
        float blue() const { return this->z(); }
};