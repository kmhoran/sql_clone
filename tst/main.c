#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "statement_parsing.c"

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(prepare_statement_when_insert_then_parses_input_command),
        cmocka_unit_test(prepare_statement_when_select_then_parses_input_command),
        cmocka_unit_test(prepare_statement_when_invalid_then_returns_failure),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
