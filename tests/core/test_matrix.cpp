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

TEST_CASE("Multiplying two matrix", "[matrix]") {
  std::vector<float> vecA = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
  std::vector<float> vecB = {-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8};
  std::vector<float> vecR = {20, 22, 50, 48, 44, 54, 114, 108, 40, 58, 110, 102, 16, 26, 46, 42};

  Matrix A(4, 4, vecA);
  Matrix B(4, 4, vecB);
  Matrix R(4, 4, vecR);

  REQUIRE( R == (A * B) );
}

TEST_CASE("Multiplying matrix and tuple", "[matrix]") {
  std::vector<float> vec = {1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1};
  Tuple T(1, 2, 3, 1);
  Matrix A(4, 4, vec);

  REQUIRE( A * T == Tuple(18, 24, 33, 1) );
}

TEST_CASE("Multiplying a matrix by the identity matrix", "[matrix]") {
  std::vector<float> vec = {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32};
  Matrix A(4, 4, vec);

  REQUIRE( A * IdentityMatrix(4) == A );
}

TEST_CASE("Multiplying the identity matrix by a tuple", "[matrix]") {
  Tuple T(1, 2, 3, 4);

  REQUIRE( IdentityMatrix(4) * T == T );
}

TEST_CASE("Transposing a matrix", "[matrix]") {
  std::vector<float> vec = {0, 9, 3, 0, 9, 8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8};
  std::vector<float> vecT = {0, 9, 1, 0, 9, 8, 8, 0, 3, 0, 5, 5, 0, 8, 3, 8};
  Matrix A(4, 4, vec);
  Matrix AT(4, 4, vecT);

  REQUIRE( A.Transpose() == AT );
}


TEST_CASE("Transposing the identity matrix", "[matrix]") { 
  REQUIRE( IdentityMatrix(4).Transpose() == IdentityMatrix(4) );
}