#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/input_buffer.h"
#include "../src/statement_parsing.h"

static void prepare_statement_when_insert_then_parses_input_command()
{
    InputBuffer *input_buffer = new_input_buffer();
    input_buffer->buffer = "select";

    Statement statement;
    prepare_statement(input_buffer, &statement);
    assert_int_equal(STATEMENT_SELECT, statement.type);
}