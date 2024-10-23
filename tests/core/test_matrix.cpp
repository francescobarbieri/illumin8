#include "Illumin8/matrix.h"
#include <catch2/catch_all.hpp>
#include <vector>

TEST_CASE("Constructing and inspecting a matrix", "[matrix]") {
  std::vector<float> vec = {1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10 , 11, 12, 13.5, 14.5, 15.5, 16.5};

  auto m = new Matrix(4, 4, vec);

  REQUIRE( (*m)(0, 0) == Catch::Approx(1) );
  REQUIRE( (*m)(0, 3) == Catch::Approx(4) );
  REQUIRE( (*m)(1, 0) == Catch::Approx(5.5) );
  REQUIRE( (*m)(1, 2) == Catch::Approx(7.5) );
  REQUIRE( (*m)(2, 2) == Catch::Approx(11) );
  REQUIRE( (*m)(3, 0) == Catch::Approx(13.5) );
  REQUIRE( (*m)(3, 2) == Catch::Approx(15.5) );
}

TEST_CASE("A 2x2 matrix ought to be representable", "[matrix]") {
  std::vector<float> vec = {-3, 5 , 1 , -2};

  auto m = new Matrix(2, 2, vec);
  REQUIRE( (*m)(0, 0) == Catch::Approx(-3) );
  REQUIRE( (*m)(0, 1) == Catch::Approx(5) );
  REQUIRE( (*m)(1, 0) == Catch::Approx(1) );
  REQUIRE( (*m)(1, 1) == Catch::Approx(-2) );
}

TEST_CASE("A 3x3 matrix ought to be representable", "[matrix]") {
  std::vector<float> vec = {-3, 5, 0, 1 , -2, -7, 0, 1, 1};

  auto m = new Matrix(3, 3, vec);
  REQUIRE( (*m)(0, 0) == Catch::Approx(-3) );
  REQUIRE( (*m)(1, 1) == Catch::Approx(-2) );
  REQUIRE( (*m)(2, 2) == Catch::Approx(1) );
}

TEST_CASE("Matrix equality with identical matrices", "[matrix]") {
  std::vector<float> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};

  Matrix m1(4, 4, vec);
  Matrix m2(4, 4, vec);

  REQUIRE( m1 == m2 );
}

TEST_CASE("Matrix equality with different matrices", "[matrix]") {
  std::vector<float> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
  std::vector<float> vec2 = {2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  Matrix m1(4, 4, vec1);
  Matrix m2(4, 4, vec2);

  REQUIRE( !(m1 == m2) );
}