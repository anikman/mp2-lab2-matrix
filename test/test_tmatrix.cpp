#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5), expBf(5);
	m[1][2] = 3;
	expBf[1][2] = 3;
	TMatrix<int> m1(m);
	EXPECT_EQ(expBf, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	m[1][2] = 3;
	TMatrix<int> m1(m);
	m1[1][2] = 5;
	EXPECT_NE(m[1][2], m1[1][2]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m.GetSize());
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m[1][2] = 3);
	EXPECT_EQ(3, m[1][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[1][-2] = 3);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[1][50] = 3);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5), expBf(5);
	m[2][3] = 1;
	expBf[2][3] = 1;
	ASSERT_NO_THROW(m = m);
	EXPECT_EQ(m, expBf);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	const int size = 5;
	TMatrix<int> m1(size), m2(5), expBf(size);
	m1[1][1] = 5;
	expBf[1][1] = 5;
	ASSERT_NO_THROW(m2 = m1);
	EXPECT_EQ(expBf, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	const int size1 = 5, size2 = 10;
	TMatrix<int> m1(size1), m2(size2);
	m1[1][1] = 5;
	ASSERT_NO_THROW(m2 = m1);
	EXPECT_EQ(size1, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	const int size1 = 5, size2 = 10;
	TMatrix<int> m1(size1), m2(size2), expBf(size1);
	m1[1][1] = 5;
	expBf[1][1] = 5;
	ASSERT_NO_THROW(m2 = m1);
	EXPECT_EQ(expBf, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(5), m2(5);
	m1[1][1] = 5;
	m2[1][1] = 5;
	ASSERT_TRUE(m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(5);
	m1[1][1] = 5;
	ASSERT_TRUE(m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	const int size1 = 5, size2 = 10;
	TMatrix<int> m1(size1), m2(size2);
	m1[1][1] = 5;
	m2[1][1] = 5;
	ASSERT_FALSE(m1 == m2);
	ASSERT_TRUE(m1 != m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	const int size = 3;
	TMatrix<int> m1(size);
	m1[0][0] = 3;
	m1[0][2] = 2;
	m1[1][1] = 5;
	m1[2][1] = -3;
	m1[2][2] = -10;
	TMatrix<int> m2(size);
	m2[0][1] = 3;
	m2[0][2] = 2;
	m2[1][1] = -2;
	m2[2][1] = 3;
	m2[2][2] = 1;
	TMatrix<int> expBf(size);
	expBf[0][0] = 3;
	expBf[0][1] = 3;
	expBf[0][2] = 4;
	expBf[1][1] = 3;
	expBf[2][2] = -9;
	EXPECT_EQ(expBf, m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	const int size1 = 3, size2 = 100;
	TMatrix<int> m1(size1), m2(size2);
	m1[0][0] = 3;
	m2[1][1] = 4;
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	const int size = 2;
	TMatrix<int> m1(size);
	m1[0][0] = 1;
	m1[0][1] = -2;
	m1[1][1] = 2;
	TMatrix<int> m2(size);
	m2[0][0] = 5;
	m2[0][1] = -2;
	m2[1][1] = 2;
	TMatrix<int> expBf(size);
	expBf[0][0] = -4;
	EXPECT_EQ(expBf, m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const int size1 = 10, size2 = 3;
	TMatrix<int> m1(size1), m2(size2);
	m1[0][0] = 3;
	m2[1][1] = 4;
	ASSERT_ANY_THROW(m1 - m2);
}

