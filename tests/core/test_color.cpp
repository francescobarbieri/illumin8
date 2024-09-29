#include "Illumin8/color.h"
#include <catch2/catch_all.hpp>

TEST_CASE("Colors are (red, green, blue) tuples", "[.color]") {
    const auto c = Color(-0.5 , 0.4, 1.7);

    REQUIRE(c.red() == Catch::Approx(-0.5));
    REQUIRE(c.green() == Catch::Approx(0.4));
    REQUIRE(c.blue() == Catch::Approx(1.7));
}

TEST_CASE("Adding colors", "[.color]") {
    const auto c1 = Color(0.9 , 0.6, 0.75);
    const auto c2 = Color(0.7 , 0.1, 0.25);

    REQUIRE(c1 + c2 == Color(1.6, 0.7 , 1.0));
}

TEST_CASE("Subtracting colors", "[.color]") {
    const auto c1 = Color(0.9 , 0.6, 0.75);
    const auto c2 = Color(0.7 , 0.1, 0.25);

    REQUIRE(c1 - c2 == Color(0.2, 0.5, 0.5));
}

TEST_CASE("Multiplying a color by a scalar", "[.color]") {
    const auto c = Color(0.2, 0.3, 0.4);

    REQUIRE(c * 2 == Color(0.4, 0.6, 0.8));
}

TEST_CASE("Multiplying colors", "[.color]") {
    const auto c1 = Color(1, 0.2, 0.4);
    const auto c2 = Color(0.9, 1, 0.1);

    REQUIRE(c1 * c2 == Color(0.9, 0.2, 0.04));
}