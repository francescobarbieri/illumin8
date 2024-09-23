class Tuple {
    public:
        Tuple() {};
        Tuple(float x, float y, float z, float w);

        float x() const { return x_; }
        float y() const { return y_; }
        float z() const { return z_; }
        float w() const { return w_; }
        void setW(float w) { w_ = w; }

        bool isPoint() const;
        bool isVector() const;

    private:
        float x_, y_, z_, w_;
};

bool operator==(const Tuple lhs, const Tuple rhs);
Tuple operator+(const Tuple lhs, const Tuple rhs);

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);