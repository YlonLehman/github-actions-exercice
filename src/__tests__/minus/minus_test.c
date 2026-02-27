/**
 * @author     Némo Cazin
 * @date       2026
 */

#include "minus_test.h"

// Test case for subtracting two positive numbers
START_TEST(test_minus_positive_numbers)
{
    int a = 10;
    int b = 5;

    int result = minus(a, b);

    ck_assert_int_eq(result, 5);
}
END_TEST

// Test case for subtracting two negative numbers
START_TEST(test_minus_negative_numbers)
{
    int a = -5;
    int b = -10;

    int result = minus(a, b);

    ck_assert_int_eq(result, 5);
}
END_TEST

// Test case for subtracting positive and negative numbers
START_TEST(test_minus_positive_and_negative_numbers)
{
    int a = -5;
    int b = 10;

    int result = minus(a, b);

    ck_assert_int_eq(result, -15);
}
END_TEST

// Test case for subtracting zero and a positive number
START_TEST(test_minus_zero_and_positive)
{
    int a = 0;
    int b = 10;

    int result = minus(a, b);

    ck_assert_int_eq(result, -10);
}
END_TEST

// Test case for subtracting zero and a negative number
START_TEST(test_minus_zero_and_negative)
{
    int a = 0;
    int b = -10;

    int result = minus(a, b);

    ck_assert_int_eq(result, 10);
}
END_TEST

Suite* minus_suite(void) {
    Suite* s;
    TCase* tc_minus;

    s = suite_create("Minus");

    // Add tests
    tc_minus = tcase_create("Minus ");
    tcase_add_test(tc_minus, test_minus_positive_numbers);
    tcase_add_test(tc_minus, test_minus_negative_numbers);
    tcase_add_test(tc_minus, test_minus_positive_and_negative_numbers);
    tcase_add_test(tc_minus, test_minus_zero_and_positive);
    tcase_add_test(tc_minus, test_minus_zero_and_negative);
    suite_add_tcase(s, tc_minus);

    return s;
}
