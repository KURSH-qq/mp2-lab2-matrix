#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> a(10), b(a);
	EXPECT_EQ(a, b);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> a(5),b(a);
	for (int i = 0; i<5; i++) {
		for (int j = 0; j < 5; j++) {
			b[i][j] = i;
		}
	}
	EXPECT_NE(a, b);
	
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> a(10);
	EXPECT_EQ(a.size(), 10);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> a(10);
	ASSERT_NO_THROW(a[1][1] = 5);
	EXPECT_EQ(a[1][1], 5);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> a(2);
	ASSERT_ANY_THROW(a.at(-1).at(1) = 1);
	ASSERT_ANY_THROW(a.at(1).at(-1) = 1);
	ASSERT_ANY_THROW(a.at(-1).at(-1) = 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> a(2);
	ASSERT_ANY_THROW(a.at(3).at(1) = 1);
	ASSERT_ANY_THROW(a.at(1).at(3) = 1);
	ASSERT_ANY_THROW(a.at(3).at(3) = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> a(2);
	ASSERT_NO_THROW(a = a);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> a(5), b(5);
	a = b;
	EXPECT_EQ(a, b);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> a(5), b(6);
	b = a;
	EXPECT_EQ(b.size(), 5);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> a(5), b(6);
	b = a;
	EXPECT_EQ(b, a);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> a(5), b(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
			b[i][j] = i;
		}
	}
	EXPECT_EQ(a == b, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> a(5);
	EXPECT_EQ(true, a == a);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> a(5), b(6);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			b[i][j] = i;
		}
	}
	EXPECT_EQ(false, b == a);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(3), b(3),c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = i;
			b[i][j] = i + 1;
		}
	}
	c = a + b;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			EXPECT_EQ(c[i][j], 2 * i + 1);
		}
	}
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> a(3), b(4), c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = i;
			b[i][j] = i + 1;
		}
	}
	ASSERT_ANY_THROW(c = a + b);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(3), b(3), c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = i;
			b[i][j] = i + 1;
		}
	}
	c = b- a;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			EXPECT_EQ(c[i][j], -1);
		}
	}
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> a(3), b(4), c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = i;
			b[i][j] = i + 1;
		}
	}
	ASSERT_ANY_THROW(c = b- a);
}

