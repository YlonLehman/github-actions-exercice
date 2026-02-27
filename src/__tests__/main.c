#include <check.h>
#include "add/add_test.h"
#include "minus/minus_test.h"

int main(void)
{
    SRunner* sr = srunner_create(add_suite());
    srunner_add_suite(sr, minus_suite());
    srunner_run_all(sr, CK_NORMAL);
    int failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return failed == 0 ? 0 : 1;
}