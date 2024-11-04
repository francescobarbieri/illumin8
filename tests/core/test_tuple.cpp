#include "Illumin8/tuple.h"
#include <catch2/catch_all.hpp>
#include <cmath>

TEST_CASE("A tuple with w=1.0 is a point", "[.tuple]") {
    const auto tuple = new Tuple(4.3, -4.2, 3.1, 1.0);

    REQUIRE(tuple->x() == Catch::Approx(4.3));
    REQUIRE(tuple->y() == Catch::Approx(-4.2));
    REQUIRE(tuple->z() == Catch::Approx(3.1));
    REQUIRE(tuple->w() == Catch::Approx(1.0));

    REQUIRE(tuple->isPoint() == true);
    REQUIRE(tuple->isVector() == false);
}

TEST_CASE("A tuple with w=0 is a vector", "[.tuple]") {
    const auto tuple = new Tuple(4.3, -4.2, 3.1, 0.0);

    REQUIRE(tuple->x() == Catch::Approx(4.3));
    REQUIRE(tuple->y() == Catch::Approx(-4.2));
    REQUIRE(tuple->z() == Catch::Approx(3.1));
    REQUIRE(tuple->w() == Catch::Approx(0.0));

    REQUIRE(tuple->isPoint() == false);
    REQUIRE(tuple->isVector() == true);
}

TEST_CASE("point() creates tuples with w=1", "[.tuple]") {
    const auto p = Point(4.0, -4.0, 3.0);
    const auto point_tuple = Tuple(4.0, -4.0, 3.0, 1);

    REQUIRE(p == point_tuple);
}

TEST_CASE("vector() creates tuples with w=0", "[.tuple]") {
    const auto v = Vector(4.0, -4.0, 3.0);
    const auto vector_tuple = Tuple(4.0, -4.0, 3.0, 0);

    REQUIRE(v == vector_tuple);
}

TEST_CASE("Adding two tuples", "[.tuple]") {
    const auto a1 = Tuple(3.0, -2.0, 5.0, 1);
    const auto a2 = Tuple(-2.0, 3.0, 1.0, 0);

    REQUIRE( a1 + a2 == Tuple(1, 1, 6 ,1) );
}

TEST_CASE("Subtracting two points", "[.tuple]") {
    const auto p1 = Point(3, 2, 1);
    const auto p2 = Point(5, 6, 7);

    REQUIRE( p1 - p2 == Vector(-2, -4, -6) );
}

TEST_CASE("Subtracting a vector from a point", "[.tuple]") {
    const auto p = Point(3, 2, 1);
    const auto v = Vector(5, 6, 7);

    REQUIRE( p - v == Point(-2, -4, -6) );
}

TEST_CASE("Subtracting two vectors", "[.tuple]") {
    const auto v1 = Vector(3, 2, 1);
    const auto v2 = Vector(5, 6, 7);

    REQUIRE( v1 - v2 == Vector(-2, -4, -6) );
}

TEST_CASE("Subtracting a vector from the zero vector", "[.tuple]") {
    const auto zero = Vector(0, 0, 0);
    const auto v = Vector(1, -2, 3);

    REQUIRE( zero - v == Vector(-1, 2, -3) );
}

TEST_CASE("Negating a tuple", "[.tuple]") {
    auto a = Tuple(1, -2, 3, -4);

    REQUIRE( -a == Tuple(-1, 2, -3, 4));
}

TEST_CASE("Multiplying a tuple by a scalar", "[.tuple]") {
    const auto a = Tuple(1, -2, 3, -4);

    REQUIRE( a * 3.5 == Tuple(3.5, -7, 10.5, -14) );
}

TEST_CASE("Multiplying a tuple by a fraction", "[.tuple]") {
    const auto a = Tuple(1, -2, 3, -4);

    REQUIRE( a * 0.5 == Tuple(0.5, -1, 1.5, -2) );
}

TEST_CASE("Dividing a tuple by a scalar", "[.tuple]") {
    const auto a = Tuple(1, -2, 3, -4);

    REQUIRE ( a / 2.0 == Tuple(0.5, -1, 1.5, -2) );
}

TEST_CASE("Computing the magnitude of vectors", "[.tuple]") {
    const auto v1 = Vector(1, 0, 0);
    const auto v2 = Vector(0, 1 ,0);
    const auto v3 = Vector(0, 0, 1);
    const auto v4 = Vector(1, 2, 3);
    const auto v5 = Vector(-1, -2, -3);

    REQUIRE ( v1.magnitude() == 1 );
    REQUIRE ( v2.magnitude() == 1 );
    REQUIRE ( v3.magnitude() == 1 ); 
    REQUIRE ( v4.magnitude() == Catch::Approx(std::sqrt(14)) );
    REQUIRE ( v5.magnitude() == Catch::Approx(std::sqrt(14)) );
}

TEST_CASE("Normalizing vectors", "[.tuple]") {
    const auto v1 = Vector(4, 0, 0);
    const auto v2 = Vector(1, 2 ,3);

    REQUIRE ( v1.normalize() == Vector(1, 0, 0) );
    REQUIRE ( v2.normalize() == Vector(0.26726, 0.53452, 0.80178) );
}

TEST_CASE("Magnitude of a normalized vector", "[.tuple]") {
    const auto v = Vector(1, 2, 3);
    Tuple norm = v.normalize();

    REQUIRE ( norm.magnitude() == Catch::Approx(1) );
}

TEST_CASE("The dot product of two tuples", "[.tuple]") {
    const auto a = Vector(1, 2, 3);
    const auto b = Vector(2, 3, 4);

    REQUIRE( a.dot(b) == Catch::Approx(20) );
}

TEST_CASE("The cross product of two vectors", "[.tuple]") {
    const auto a = Vector(1, 2, 3);
    const auto b = Vector(2, 3, 4);

    REQUIRE( a.cross(b) == Vector(-1, 2, -1) );
    REQUIRE( b.cross(a) == Vector(1, -2, 1) );
}

TEST_CASE("Reflecting a vector approaching at 45°", "[tuple]") {
    Tuple v = Vector(1, -1, 0);
    Tuple n = Vector(0, 1, 0);
    Tuple r = v.Reflect(n);

    REQUIRE( r == Vector(1, 1, 0) );
}

TEST_CASE("Reflecting a vector off a slanted surface", "[tuple]") {
    Tuple v = Vector(0, -1, 0);
    Tuple n = Vector(sqrt(2)/2, sqrt(2)/2, 0);
    Tuple r = v.Reflect(n);

    REQUIRE( r == Vector(1, 0, 0) );
}