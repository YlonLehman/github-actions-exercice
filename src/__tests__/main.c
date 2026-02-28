/**
 * @author     Némo Cazin
 * @date       2026
 */

#include <check.h>

#include "add/add_test.h"
#include "minus/minus_test.h"

int main(void) {
    SRunner* suiteRunner = srunner_create(add_suite());
    srunner_add_suite(suiteRunner, minus_suite());
    srunner_run_all(suiteRunner, CK_NORMAL);
    int failed = srunner_ntests_failed(suiteRunner);
    srunner_free(suiteRunner);
    return failed == 0 ? 0 : 1;
}
