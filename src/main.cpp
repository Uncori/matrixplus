#include <gtest/gtest.h>

#include "matrix_oop.h"

TEST(EqMatrix, True) {
    Matrix matrix_a(3, 3);
    Matrix matrix_b(3, 3);
    ASSERT_TRUE(matrix_a == matrix_b);
}
TEST(EqMatrix, False) {
    Matrix matrix_a(3, 3);
    Matrix matrix_b(2, 2);
    ASSERT_FALSE(matrix_a == matrix_b);
}
TEST(SumMatrix, True) {
    Matrix matrix_a(2, 2);
    Matrix matrix_b(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = 3.14;
    matrix_a(0, 1) = 0.56;
    matrix_a(1, 0) = -69.3;
    matrix_a(1, 1) = 0;

    matrix_b(0, 0) = -78.14;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -0.3;
    matrix_b(1, 1) = 2;

    result(0, 0) = -75;
    result(0, 1) = 0.56;
    result(1, 0) = -69.6;
    result(1, 1) = 2;
    matrix_a.sum_matrix(matrix_b);
    ASSERT_TRUE(matrix_a == result);
}
TEST(SumMatrix, False) {
    Matrix matrix_a(1, 2);
    Matrix matrix_b(2, 2);

    matrix_a(0, 0) = 3.14;
    matrix_a(0, 1) = 0.56;

    matrix_b(0, 0) = -78.14;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -0.3;
    matrix_b(1, 1) = 2;

    EXPECT_THROW(matrix_a.sum_matrix(matrix_b), std::out_of_range);
}
TEST(SubMatrix, True) {
    Matrix matrix_a(2, 2);
    Matrix matrix_b(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = -6;
    matrix_a(1, 1) = 0;

    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3;
    matrix_b(1, 1) = 2;

    result(0, 0) = 10;
    result(0, 1) = 2;
    result(1, 0) = -3;
    result(1, 1) = -2;

    matrix_a.sub_matrix(matrix_b);

    ASSERT_TRUE(matrix_a == result);
}
TEST(SubMatrix, False) {
    Matrix matrix_a(1, 2);
    Matrix matrix_b(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;

    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3;
    matrix_b(1, 1) = 2;

    EXPECT_THROW(matrix_a.sub_matrix(matrix_b), std::out_of_range);
}
TEST(MulNumber, True) {
    Matrix matrix_a(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = -78.14;
    matrix_a(0, 1) = 0;
    matrix_a(1, 0) = -0.3;
    matrix_a(1, 1) = 2;

    result(0, 0) = -781.4;
    result(0, 1) = 0;
    result(1, 0) = -3;
    result(1, 1) = 20;

    matrix_a.mul_number(10);

    ASSERT_TRUE(matrix_a == result);
}
TEST(MulMatrix, True) {
    Matrix matrix_a(2, 2);
    Matrix matrix_b(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = -6.6;
    matrix_a(1, 1) = 0;

    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3.5;
    matrix_b(1, 1) = 2;

    result(0, 0) = -28;
    result(0, 1) = 4;
    result(1, 0) = 46.2;
    result(1, 1) = 0;

    matrix_a.mul_matrix(matrix_b);

    ASSERT_TRUE(matrix_a == result);
}
TEST(MulMatrix, False) {
    Matrix matrix_a(2, 1);
    Matrix matrix_b(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(1, 0) = -6.6;

    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3.5;
    matrix_b(1, 1) = 2;

    EXPECT_THROW(matrix_a.mul_matrix(matrix_b), std::out_of_range);
}
TEST(OperatorParentheses, True) {
    Matrix matrix_a(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = -6.6;
    matrix_a(1, 1) = 0;
    ASSERT_EQ(matrix_a(0, 1), 2);
}
TEST(OperatorParentheses, False) {
    Matrix matrix_a(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = -6.6;
    matrix_a(1, 1) = 0;
    ASSERT_NE(matrix_a(0, 1), 10);
}
TEST(OperatorPlus, True) {
    Matrix matrix_a(2, 2);
    Matrix matrix_b(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = 3.14;
    matrix_a(0, 1) = 0.56;
    matrix_a(1, 0) = -69.3;
    matrix_a(1, 1) = 0;

    matrix_b(0, 0) = -78.14;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -0.3;
    matrix_b(1, 1) = 2;

    result(0, 0) = -75;
    result(0, 1) = 0.56;
    result(1, 0) = -69.6;
    result(1, 1) = 2;

    ASSERT_TRUE((matrix_a + matrix_b) == result);
}
TEST(OperatorMinus, True) {
    Matrix matrix_a(2, 2);
    Matrix matrix_b(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = -6;
    matrix_a(1, 1) = 0;

    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3;
    matrix_b(1, 1) = 2;

    result(0, 0) = 10;
    result(0, 1) = 2;
    result(1, 0) = -3;
    result(1, 1) = -2;

    ASSERT_TRUE((matrix_a - matrix_b) == result);
}
TEST(OperatorMultiplyMatrix, True) {
    Matrix matrix_a(2, 2);
    Matrix matrix_b(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = -6.6;
    matrix_a(1, 1) = 0;

    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3.5;
    matrix_b(1, 1) = 2;

    result(0, 0) = -28;
    result(0, 1) = 4;
    result(1, 0) = 46.2;
    result(1, 1) = 0;

    ASSERT_TRUE((matrix_a * matrix_b) == result);
}
TEST(OperatorMultiplyNumber, True) {
    Matrix matrix_a(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = -78.14;
    matrix_a(0, 1) = 0;
    matrix_a(1, 0) = -0.3;
    matrix_a(1, 1) = 2;

    result(0, 0) = -781.4;
    result(0, 1) = 0;
    result(1, 0) = -3;
    result(1, 1) = 20;

    ASSERT_TRUE((matrix_a * 10) == result);
}
TEST(OperatorMultiplyNum, True) {
    Matrix matrix_a(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = -78.14;
    matrix_a(0, 1) = 0;
    matrix_a(1, 0) = -0.3;
    matrix_a(1, 1) = 2;

    result(0, 0) = -781.4;
    result(0, 1) = 0;
    result(1, 0) = -3;
    result(1, 1) = 20;

    ASSERT_TRUE((10 * matrix_a) == result);
}
TEST(OperatorEqMatrix, True) {
    Matrix matrix_a(3, 3);
    Matrix matrix_b(1, 3);
    matrix_a = matrix_b;
    ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(OperatorSumMatrix, True) {
    Matrix matrix_a(2, 2);
    Matrix matrix_b(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = 3.14;
    matrix_a(0, 1) = 0.56;
    matrix_a(1, 0) = -69.3;
    matrix_a(1, 1) = 0;

    matrix_b(0, 0) = -78.14;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -0.3;
    matrix_b(1, 1) = 2;

    result(0, 0) = -75;
    result(0, 1) = 0.56;
    result(1, 0) = -69.6;
    result(1, 1) = 2;

    ASSERT_TRUE((matrix_a += matrix_b) == result);
}
TEST(OperatorSumMatrix, False) {
    Matrix matrix_a(1, 2);
    Matrix matrix_b(2, 2);

    matrix_a(0, 0) = 3.14;
    matrix_a(0, 1) = 0.56;

    matrix_b(0, 0) = -78.14;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -0.3;
    matrix_b(1, 1) = 2;

    EXPECT_THROW((matrix_a += matrix_b), std::out_of_range);
}

TEST(OperatorSubMatrix, True) {
    Matrix matrix_a(2, 2);
    Matrix matrix_b(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = -6;
    matrix_a(1, 1) = 0;

    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3;
    matrix_b(1, 1) = 2;

    result(0, 0) = 10;
    result(0, 1) = 2;
    result(1, 0) = -3;
    result(1, 1) = -2;

    ASSERT_TRUE((matrix_a -= matrix_b) == result);
}
TEST(OperatorSubMatrix, False) {
    Matrix matrix_a(1, 2);
    Matrix matrix_b(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;

    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3;
    matrix_b(1, 1) = 2;

    EXPECT_THROW(matrix_a -= matrix_b, std::out_of_range);
}
TEST(OperatorMulNumber, True) {
    Matrix matrix_a(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = -78.14;
    matrix_a(0, 1) = 0;
    matrix_a(1, 0) = -0.3;
    matrix_a(1, 1) = 2;

    result(0, 0) = -781.4;
    result(0, 1) = 0;
    result(1, 0) = -3;
    result(1, 1) = 20;

    ASSERT_TRUE((matrix_a *= 10) == result);
}
TEST(OperatorMulMatrix, True) {
    Matrix matrix_a(2, 2);
    Matrix matrix_b(2, 2);
    Matrix result(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = -6.6;
    matrix_a(1, 1) = 0;

    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3.5;
    matrix_b(1, 1) = 2;

    result(0, 0) = -28;
    result(0, 1) = 4;
    result(1, 0) = 46.2;
    result(1, 1) = 0;

    ASSERT_TRUE((matrix_a *= matrix_b) == result);
}
TEST(OperatorMulMatrix, False) {
    Matrix matrix_a(2, 1);
    Matrix matrix_b(2, 2);

    matrix_a(0, 0) = 3;
    matrix_a(1, 0) = -6.6;

    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3.5;
    matrix_b(1, 1) = 2;

    EXPECT_THROW(matrix_a *= matrix_b, std::out_of_range);
}
TEST(Transpose, True) {
    Matrix matrix_a(4, 3);
    Matrix result(3, 4);

    matrix_a(0, 0) = 7;
    matrix_a(0, 1) = -98;
    matrix_a(0, 2) = 0.5;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = 5.4;
    matrix_a(1, 2) = 32;
    matrix_a(2, 0) = 3.12;
    matrix_a(2, 1) = 2323;
    matrix_a(2, 2) = 23;
    matrix_a(3, 0) = -78;
    matrix_a(3, 1) = 476.4;
    matrix_a(3, 2) = 21;

    result(0, 0) = 7;
    result(0, 1) = 0;
    result(0, 2) = 3.12;
    result(0, 3) = -78;
    result(1, 0) = -98;
    result(1, 1) = 5.4;
    result(1, 2) = 2323;
    result(1, 3) = 476.4;
    result(2, 0) = 0.5;
    result(2, 1) = 32;
    result(2, 2) = 23;
    result(2, 3) = 21;
    Matrix res = matrix_a.transpose();
    ASSERT_TRUE(res == result);
}

TEST(Inverse, False) {
    Matrix matrix_a(4, 3);
    Matrix result(3, 4);

    matrix_a(0, 0) = 7;
    matrix_a(0, 1) = -98;
    matrix_a(0, 2) = 0.5;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = 5.4;
    matrix_a(1, 2) = 32;
    matrix_a(2, 0) = 3.12;
    matrix_a(2, 1) = 2323;
    matrix_a(2, 2) = 23;
    matrix_a(3, 0) = -78;
    matrix_a(3, 1) = 476.4;
    matrix_a(3, 2) = 21;

    EXPECT_THROW(matrix_a.inverse_matrix(), std::out_of_range);
}
TEST(Inverse, True) {
    Matrix matrix_a(3, 3);
    Matrix result(3, 3);

    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 5;
    matrix_a(0, 2) = 7;
    matrix_a(1, 0) = 6;
    matrix_a(1, 1) = 3;
    matrix_a(1, 2) = 4;
    matrix_a(2, 0) = 5;
    matrix_a(2, 1) = -2;
    matrix_a(2, 2) = -3;

    result(0, 0) = 1;
    result(0, 1) = -1;
    result(0, 2) = 1;
    result(1, 0) = -38;
    result(1, 1) = 41;
    result(1, 2) = -34;
    result(2, 0) = 27;
    result(2, 1) = -29;
    result(2, 2) = 24;

    ASSERT_TRUE(matrix_a.inverse_matrix().eq_matrix(result));

    Matrix matrix_b(3, 3);
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 2;
    matrix_b(0, 2) = 3;
    matrix_b(1, 0) = 4;
    matrix_b(1, 1) = 5;
    matrix_b(1, 2) = 6;
    matrix_b(2, 0) = 7;
    matrix_b(2, 1) = 8;
    matrix_b(2, 2) = 9;

    EXPECT_THROW(matrix_b.inverse_matrix(), std::out_of_range);
}
TEST(Get, True) {
    Matrix matrix_a(3, 3);

    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 5;
    matrix_a(0, 2) = 7;
    matrix_a(1, 0) = 6;
    matrix_a(1, 1) = 3;
    matrix_a(1, 2) = 4;
    matrix_a(2, 0) = 5;
    matrix_a(2, 1) = -2;
    matrix_a(2, 2) = -3;

    ASSERT_EQ(matrix_a.get_rows(), 3);
    ASSERT_EQ(matrix_a.get_cols(), 3);
}
TEST(Set, True) {
    Matrix matrix_a(3, 3);
    Matrix result(3, 2);

    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 5;
    matrix_a(0, 2) = 7;
    matrix_a(1, 0) = 6;
    matrix_a(1, 1) = 3;
    matrix_a(1, 2) = 4;
    matrix_a(2, 0) = 5;
    matrix_a(2, 1) = -2;
    matrix_a(2, 2) = -3;

    result(0, 0) = 2;
    result(0, 1) = 5;

    result(1, 0) = 6;
    result(1, 1) = 3;

    result(2, 0) = 5;
    result(2, 1) = -2;
    matrix_a.set_cols(2);

    ASSERT_TRUE(matrix_a == result);

    Matrix matrix_b(3, 3);
    Matrix result_b(2, 3);

    matrix_b(0, 0) = 2;
    matrix_b(0, 1) = 5;
    matrix_b(0, 2) = 7;
    matrix_b(1, 0) = 6;
    matrix_b(1, 1) = 3;
    matrix_b(1, 2) = 4;
    matrix_b(2, 0) = 5;
    matrix_b(2, 1) = -2;
    matrix_b(2, 2) = -3;

    result_b(0, 0) = 2;
    result_b(0, 1) = 5;
    result_b(0, 2) = 7;
    result_b(1, 0) = 6;
    result_b(1, 1) = 3;
    result_b(1, 2) = 4;

    matrix_b.set_rows(2);
    ASSERT_TRUE(matrix_b == result_b);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
