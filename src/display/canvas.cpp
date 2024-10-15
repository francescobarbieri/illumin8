#include "canvas.h"
#include <fstream>

Canvas::Canvas(int w, int h)
{
    this->w_ = w;
    this->h_ = h;
    this->pixels = std::vector<std::vector<Color>>(w, std::vector<Color>(h, Color(0, 0, 0)));
}

void Canvas::write_pixel(int w, int h, Color c)
{
    if(w >= 0 && w < w_ && h >= 0 && h < h_ ) {
        pixels[w][h] = c;
    }
}

Color Canvas::pixel_at(int w, int h)
{
    if(w >= 0 && w < w_ && h >= 0 && h < h_ ) {
        return pixels[w][h];
    }

    return Color(0, 0, 0); 
}

void Canvas::canvas_to_ppm()
{
    std::ofstream file("image.ppm");
    file << "P3\n" << w_ << " " << h_ << "\n255\n";
    for(const auto row : pixels) {
        for(const auto pixel : row) {
            file << static_cast<int>(pixel.red() * 255) << " "
                 << static_cast<int>(pixel.green() * 255) << " "
                 << static_cast<int>(pixel.blue() * 255) << "\n";
        }
    }
    file.close();
}
