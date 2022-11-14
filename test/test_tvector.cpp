#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> a(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	
	TDynamicVector<int> b(a);
	for (int i = 0; i < a.size(); i++)
	{
		EXPECT_EQ(b[i], i);
	}
	EXPECT_EQ(b.size(), 3);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(a);
	for (int i = 0; i < 5; i++) {
		b[i] += 1;
	}
	for (int i = 0; i < 5; i++) {
		EXPECT_NE(a[i], b[i]);
	}
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> vec(5);
	ASSERT_ANY_THROW(vec.at(-1) = 5);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> vec(5);
	ASSERT_ANY_THROW(vec.at(6) = 5);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> a(2);
	a[0] = 1;
	a = a;
	EXPECT_EQ(a, a);

}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> a(5), b(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	b = a;
	EXPECT_EQ(b, a);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> a(5), b(6);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	b = a;
	EXPECT_EQ(b, a);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> a(5), b(6);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	for (int i = 0; i < 6; i++) {
		b[i] = i+1;
	}
	b = a;
	EXPECT_EQ(b, a);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> a(3), b(3);
	for (int i = 0; i < 3; i++) {
		a[i] = i;
		b[i] = i;
	}
	EXPECT_EQ(true, a == b);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> a(3);
	for (int i = 0; i < 3; i++) {
		a[i] = i;
	}
	EXPECT_EQ(true, a == a);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> a(2), b(3);
	for (int i = 0; i < 2; i++) {
		a[i] = i;
	}
	for (int i = 0; i < 3; i++) {
		b[i] = i;
	}
	EXPECT_EQ(false, a == b);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> a(3),b(3);
	for (int i = 0; i < 3; i++) {
		a[i] = i;
	}
	
	b = a + 1;
	for (int i = 0; i<3; i++) {
		EXPECT_EQ(i + 1, b[i]);
	}
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> a(3), b(3);
	for (int i = 0; i < 3; i++) {
		a[i] = i+1;
	}
	b = a-1;
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(i, b[i]);
	}
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> a(3), b(3);
	for (int i = 0; i < 3; i++) {
		a[i] = i;
	}
	b = a * 2;
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(i*2, b[i]);
	}
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> a(3), b(3), c(3);
	for (int i = 0; i < 3; i++) {
		a[i] = i;
		b[i] = i + 1;
	}
	c = a + b;
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(2 * i + 1, c[i]);
	}
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(3), b(4),c;
	for (int i = 0; i < 3; i++) {
		a[i] = i;
		b[i] = i + 1;
	}
	ASSERT_ANY_THROW(c = a + b);
	
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> a(3), b(3),c;
	for (int i = 0; i < 3; i++) {
		a[i] = i;
		b[i] = i + 1;
	}
	c = b-a;
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ( 1, c[i]);
	}
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(3), b(4), c;
	for (int i = 0; i < 3; i++) {
		a[i] = i;
		b[i] = i + 1;
	}
	ASSERT_ANY_THROW(c = b - a);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> a(3), b(3);
	for (int i = 0; i < 3; i++) {
		a[i] = i;
		b[i] = i + 1;
	}
	EXPECT_EQ(8, a*b);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(3), b(10);
	
	ASSERT_ANY_THROW( a * b);
}

