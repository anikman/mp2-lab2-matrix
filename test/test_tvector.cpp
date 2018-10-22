#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> bf1(10), expBf(10);
	for (int i = 0; i < 10; i++)
	{
		bf1[i] = i;
		expBf[i] = i;
	}
	TVector<int> bf2(bf1);
	EXPECT_EQ(expBf, bf2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> bf1(10, 0);
	TVector<int> expBf(bf1);
	bf1[2] = 1;
	EXPECT_NE(expBf, bf1);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> bf1(10, 0);
	EXPECT_ANY_THROW(bf1[-1] = 2);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> bf1(10, 0);
	EXPECT_ANY_THROW(bf1[100] = 2);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> bf1(10), expBf(10);
	bf1[3] = 2;
	expBf[3] = 2;
	ASSERT_NO_THROW(bf1 = bf1);
	bf1 = bf1;
	EXPECT_EQ(expBf, bf1);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> bf1(10), bf2(10), expBf(10);
	bf1[0] = 1;
	bf1[1] = 2;
	expBf[0] = 1;
	expBf[1] = 2;
	bf2 = bf1;
	EXPECT_EQ(expBf, bf2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	const int size = 4;
	TVector<int> bf1(size), bf2(size - 2);
	bf2 = bf1;
	EXPECT_EQ(size, bf2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	const int size1 = 4;
	const int size2 = 2;
	TVector<int> bf1(size1), bf2(size2), expBf(size1);
	bf1[0] = 1;
	bf1[1] = 2;
	bf1[2] = 3;
	expBf[0] = 1;
	expBf[1] = 2;
	expBf[2] = 3;
	bf2 = bf1;
	EXPECT_EQ(expBf, bf2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> bf1(3), bf2(3);
	bf1[0] = 1;
	bf1[1] = 2;
	bf1[2] = 3;
	bf2[0] = 1;
	bf2[1] = 2;
	bf2[2] = 3;
	ASSERT_TRUE(bf1 == bf2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> bf1(3);
	ASSERT_TRUE(bf1 == bf1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> bf1(3), bf2(10);
	ASSERT_FALSE(bf1 == bf2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> bf1(3), expBf(3);
	expBf[0] = 6;
	expBf[1] = 5;
	expBf[2] = 5;
	bf1[0] = 1;
	bf1 = bf1 + 5;
	EXPECT_EQ(expBf, bf1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> bf1(3), expBf(3);
	expBf[0] = 0;
	expBf[1] = -2;
	expBf[2] = -2;
	bf1[0] = 2;
	EXPECT_EQ(expBf, bf1 - 2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> bf1(3), expBf(3);
	expBf[0] = 9;
	expBf[1] = 3;
	expBf[2] = 3;
	bf1[0] = 3;
	bf1[1] = 1;
	bf1[2] = 1;
	EXPECT_EQ(expBf, bf1 * 3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	const int size = 10;
	TVector<int> bf1(size), bf2(size), expBf(size);
	for (int i = 0; i < size; i++)
	{
		bf1[i] = i;
		bf2[i] = i + 1;
		expBf[i] = 2 * i + 1;
	}
	EXPECT_EQ(expBf, bf1 + bf2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	const int size1 = 5, size2 = 3;
	TVector<int> bf1(size1), bf2(size2);
	EXPECT_ANY_THROW(bf1 + bf2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	const int size = 10;
	TVector<int> bf1(size), bf2(size), expBf(size);
	for (int i = 0; i < size; i++)
	{
		bf1[i] = i;
		bf2[i] = i + 1;
		expBf[i] = -1;
	}
	EXPECT_EQ(expBf, bf1 - bf2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	const int size1 = 5, size2 = 3;
	TVector<int> bf1(size1), bf2(size2);
	EXPECT_ANY_THROW(bf1 - bf2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	const int size = 2;
	TVector<int> bf1(size), bf2(size);
	bf1[0] = 4;
	bf1[1] = 3;
	bf2[0] = 3;
	bf2[1] = 2;
	EXPECT_EQ(18, bf1*bf2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	const int size1 = 3, size2 = 10;
	TVector<int> bf1(size1), bf2(size2);
	EXPECT_ANY_THROW(bf1*bf2);
}

