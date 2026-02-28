/**
 * @author     Némo Cazin
 * @date       2026
 */

#include "add_test.h"

// Test case for adding two positive numbers
START_TEST(test_add_positive_numbers) {
    int num1 = 5;
    int num2 = 10;

    int result = add(num1, num2);

    ck_assert_int_eq(result, 15);
}
END_TEST

// Test case for adding two negative numbers
START_TEST(test_add_negative_numbers) {
    int num1 = -5;
    int num2 = -10;

    int result = add(num1, num2);

    ck_assert_int_eq(result, -15);
}
END_TEST

// Test case for adding positive and negative numbers
START_TEST(test_add_positive_and_negative_numbers) {
    int num1 = -5;
    int num2 = 10;

    int result = add(num1, num2);

    ck_assert_int_eq(result, 5);
}
END_TEST

// Test case for adding zero and a positive number
START_TEST(test_add_zero_and_positive) {
    int num1 = 0;
    int num2 = 10;

    int result = add(num1, num2);

    ck_assert_int_eq(result, 10);
}
END_TEST

// Test case for adding zero and a negative number
START_TEST(test_add_zero_and_negative) {
    int num1 = 0;
    int num2 = -10;

    int result = add(num1, num2);

    ck_assert_int_eq(result, -10);
}
END_TEST

Suite* add_suite(void) {
    Suite* suite;
    TCase* tc_add;

    suite = suite_create("Add");

    // Add tests
    tc_add = tcase_create("Add ");
    tcase_add_test(tc_add, test_add_positive_numbers);
    tcase_add_test(tc_add, test_add_negative_numbers);
    tcase_add_test(tc_add, test_add_positive_and_negative_numbers);
    tcase_add_test(tc_add, test_add_zero_and_positive);
    tcase_add_test(tc_add, test_add_zero_and_negative);
    suite_add_tcase(suite, tc_add);

    return suite;
}
