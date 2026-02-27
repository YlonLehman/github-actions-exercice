/**
 * @brief      Unit tests for Add class
 *
 * @author     Némo CAZIN
 * @date       2025 - 2026
 */

#include "add_test.h"

// Test case for adding two positive numbers
START_TEST(test_add_positive_numbers)
{
    int a = 5;
    int b = 10;

    int result = add(a, b);

    ck_assert_int_eq(result, 15);
}
END_TEST

// Test case for adding two negative numbers
START_TEST(test_add_negative_numbers)
{
    int a = -5;
    int b = -10;

    int result = add(a, b);

    ck_assert_int_eq(result, -15);
}
END_TEST

// Test case for adding positive and negative numbers
START_TEST(test_add_positive_and_negative_numbers)
{
    int a = -5;
    int b = 10;

    int result = add(a, b);

    ck_assert_int_eq(result, 5);
}
END_TEST

// Test case for adding zero and a positive number
START_TEST(test_add_zero_and_positive)
{
    int a = 0;
    int b = 10;

    int result = add(a, b);

    ck_assert_int_eq(result, 10);
}
END_TEST

// Test case for adding zero and a negative number
START_TEST(test_add_zero_and_negative)
{
    int a = 0;
    int b = -10;

    int result = add(a, b);

    ck_assert_int_eq(result, -10);
}
END_TEST

Suite* add_suite(void) {
    Suite* s;
    TCase* tc_add;

    s = suite_create("Add");

    // Add tests
    tc_add = tcase_create("Add ");
    tcase_add_test(tc_add, test_add_positive_numbers);
    tcase_add_test(tc_add, test_add_negative_numbers);
    tcase_add_test(tc_add, test_add_positive_and_negative_numbers);
    tcase_add_test(tc_add, test_add_zero_and_positive);
    tcase_add_test(tc_add, test_add_zero_and_negative);
    suite_add_tcase(s, tc_add);

    return s;
}
