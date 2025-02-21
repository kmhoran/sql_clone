#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "statement_parsing.c"

static void null_test_success(void **state)
{
    (void)state;
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(prepare_statement_when_insert_then_parses_input_command),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
