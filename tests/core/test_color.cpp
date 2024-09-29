#include "Illumin8/color.h"
#include <catch2/catch_all.hpp>

TEST_CASE("Colors are (red, green, blue) tuples", "[.color]") {
    const auto c = Color(-0.5 , 0.4, 1.7);
    REQUIRE(c.red() == Catch::Approx(-0.5));
    REQUIRE(c.green() == Catch::Approx(0.4));
    REQUIRE(c.blue() == Catch::Approx(1.7));
}