#include "Illumin8/color.h"
#include <vector>

class Canvas {
    public:
        Canvas() {};
        Canvas(int w, int h);

        void write_pixel(int w, int h, Color c);
        Color pixel_at(int w, int h);
        void canvas_to_ppm();

        int width() const { return w_; }
        int height() const { return h_; }

    private:
        int w_, h_;
        std::vector<std::vector<Color>> pixels;
};