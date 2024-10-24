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

TEST_CASE("Calculating the determinant of a 2x2 matrix", "[matrix]") { 
  std::vector<float> vec = {1, 5, -3, 2};
  Matrix A(2, 2, vec);

  REQUIRE( A.Determinant() == Catch::Approx(17) );
}

TEST_CASE("A submatrix of a 3x3 matrix is a 2x2 matrix", "[matrix]") { 
  std::vector<float> vecA = {1, 5, 0, -3, 2, 7, 0, 6, -3};
  std::vector<float> vecB = {-3, 2, 0, 6};
  Matrix A(3, 3, vecA);
  Matrix B(2, 2, vecB);

  REQUIRE( A.Submatrix(0, 2) == B );
}

TEST_CASE("A submatrix of a 4x4 matrix is a 3x3 matrix", "[matrix]") { 
  std::vector<float> vecA = {-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1};
  std::vector<float> vecB = {-6, 1, 6, -8, 8, 6, -7, -1, 1};
  Matrix A(4, 4, vecA);
  Matrix B(3, 3, vecB);

  REQUIRE( A.Submatrix(2, 1) == B );
}

TEST_CASE("Calculating a minor of a 3x3 matrix", "[matrix]") { 
  std::vector<float> vec = {3, 5, 0, 2, -1, -7, 6, -1, 5};
  Matrix A(3, 3, vec);

  REQUIRE( A.Minor(1, 0) == Catch::Approx(25) );
}

TEST_CASE("Calculating a cofactor of a 3x3 matrix", "[matrix]") { 
  std::vector<float> vec = {3, 5, 0, 2, -1, -7, 6, -1, 5};
  Matrix A(3, 3, vec);

  REQUIRE( A.Minor(0, 0) == Catch::Approx(-12) );
  REQUIRE( A.Cofactor(0, 0) == Catch::Approx(-12) );
  REQUIRE( A.Minor(1, 0) == Catch::Approx(25) );
  REQUIRE( A.Cofactor(1, 0) == Catch::Approx(-25) );
}

TEST_CASE("Calculating the determinant of a 3x3 matrix", "[matrix]") { 
  std::vector<float> vec = {1, 2, 6, -5, 8, -4, 2, 6, 4};
  Matrix A(3, 3, vec);

  REQUIRE( A.Cofactor(0, 0) == Catch::Approx(56) );
  REQUIRE( A.Cofactor(0, 1) == Catch::Approx(12) );
  REQUIRE( A.Cofactor(0, 2) == Catch::Approx(-46) );
  REQUIRE( A.Determinant() == Catch::Approx(-196) );
}

TEST_CASE("Calculating the determinant of a 4x4 matrix", "[matrix]") { 
  std::vector<float> vec = {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9};
  Matrix A(4, 4, vec);

  REQUIRE( A.Cofactor(0, 0) == Catch::Approx(690) );
  REQUIRE( A.Cofactor(0, 1) == Catch::Approx(447) );
  REQUIRE( A.Cofactor(0, 2) == Catch::Approx(210) );
  REQUIRE( A.Cofactor(0, 3) == Catch::Approx(51) );
  REQUIRE( A.Determinant() == Catch::Approx(-4071) );
}

TEST_CASE("Calculating the inverse of another matrix", "[matrix]") { 
  std::vector<float> vecA = {8, -5, 9, 2, 7, 5, 6, 1, -6, 0, 9, 6, -3, 0, -9, -4};
  std::vector<float> vecB = {-0.15385, -0.15385, -0.28205, -0.53846, -0.07692, 0.12308, 0.02564, 0.03077, 0.35897, 0.35897, 0.43590, 0.92308, -0.69231, -0.69231, -0.76923, -1.92308};
  Matrix A(4, 4, vecA);
  Matrix B(4, 4, vecB);

  REQUIRE( A.Inverse() == B );
}

TEST_CASE("Multiplying a product by its inverse", "[matrix]") { 
  std::vector<float> vecA = {3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1};
  std::vector<float> vecB = {8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5};
  Matrix A(4, 4, vecA);
  Matrix B(4, 4, vecB);

  Matrix C = A * B;

  REQUIRE( C * B.Inverse() == A );
}