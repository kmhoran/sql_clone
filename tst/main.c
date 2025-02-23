#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "statement_parsing.c"
#include "utilities.c"

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(prepare_statement_when_insert_then_parses_input_command),
        cmocka_unit_test(prepare_statement_when_select_then_parses_input_command),
        cmocka_unit_test(prepare_statement_when_invalid_then_returns_failure),
        cmocka_unit_test(perform_meta_command_when_exiting_then_returns_exit),
        cmocka_unit_test(perform_meta_command_when_invalid_input_then_returns_unrecognized),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
