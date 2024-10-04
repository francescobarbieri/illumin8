#include "Illumin8/canvas.h"
#include "Illumin8/color.h"
#include <catch2/catch_all.hpp>

TEST_CASE("Creating a canvas", "[canvas]") {
    auto const c = Canvas(10, 20);

    REQUIRE(c.width() == 10);
    REQUIRE(c.height() == 20);
}

TEST_CASE("Writing pixels to a canvas", "[canvas]") {
    auto c = Canvas(10, 20);
    auto red = Color(1, 0, 0);

    c.write_pixel(2, 3, red);

    REQUIRE(c.pixel_at(2, 3) == Color(1, 0 , 0));
}

TEST_CASE("Constructing the PPM header", "[canvas]") {
    auto c = Canvas(5, 3);
    c.canvas_to_ppm();
}