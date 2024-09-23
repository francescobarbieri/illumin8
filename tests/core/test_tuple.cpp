#include "Illumin8/tuple.h"
#include <catch2/catch_all.hpp>

TEST_CASE("A tuple with w=1.0 is a point") {
    const auto tuple = new Tuple(4.3, -4.2, 3.1, 1.0);

    REQUIRE(tuple->x() == Catch::Approx(4.3));
    REQUIRE(tuple->y() == Catch::Approx(-4.2));
    REQUIRE(tuple->z() == Catch::Approx(3.1));
    REQUIRE(tuple->w() == Catch::Approx(1.0));

    REQUIRE(tuple->isPoint() == true);
    REQUIRE(tuple->isVector() == false);
}

TEST_CASE("A tuple with w=0 is a vector") {
    const auto tuple = new Tuple(4.3, -4.2, 3.1, 0.0);

    REQUIRE(tuple->x() == Catch::Approx(4.3));
    REQUIRE(tuple->y() == Catch::Approx(-4.2));
    REQUIRE(tuple->z() == Catch::Approx(3.1));
    REQUIRE(tuple->w() == Catch::Approx(0.0));

    REQUIRE(tuple->isPoint() == false);
    REQUIRE(tuple->isVector() == true);
}

TEST_CASE("point() creates tuples with w=1") {
    const auto p = Point(4.0, -4.0, 3.0);
    const auto point_tuple = Tuple(4.0, -4.0, 3.0, 1);

    REQUIRE(p == point_tuple);
}

TEST_CASE("vector() creates tuples with w=0") {
    const auto v = Vector(4.0, -4.0, 3.0);
    const auto vector_tuple = Tuple(4.0, -4.0, 3.0, 0);

    REQUIRE(v == vector_tuple);
}

TEST_CASE("Adding two tuples") {
    const auto a1 = Tuple(3.0, -2.0, 5.0, 1);
    const auto a2 = Tuple(-2.0, 3.0, 1.0, 0);

    REQUIRE( a1 + a2 == Tuple(1, 1, 6 ,1) );
}