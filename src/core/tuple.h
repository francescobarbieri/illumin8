#ifndef TUPLE_H
#define TUPLE_H

class Tuple {
    public:
        Tuple() {};
        Tuple(float x, float y, float z, float w);

        float x() const { return x_; }
        float y() const { return y_; }
        float z() const { return z_; }
        float w() const { return w_; }
        void setW(float w) { w_ = w; }

        float magnitude() const;
        Tuple normalize() const;
        float dot(Tuple tup) const;
        Tuple cross(Tuple tup) const;

        bool isPoint() const;
        bool isVector() const;

    private:
        float x_, y_, z_, w_;
};

bool operator==(const Tuple lhs, const Tuple rhs);
Tuple operator+(const Tuple lhs, const Tuple rhs);
Tuple operator-(const Tuple lhs, const Tuple rhs);
Tuple operator-(const Tuple neg);
Tuple operator*(const Tuple tup, float alpha);
Tuple operator/(const Tuple tup, float alpha);

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);

#endif