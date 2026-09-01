class Complex
{
    float re, im;
    public:
        Complex(float x = 0, float y = 0): re(x), im(y) {}
        Complex operator* (Complex rhs) const;
        void print() const;
};