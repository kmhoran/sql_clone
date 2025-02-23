#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/enums.h"
#include "../src/utilities.h"
#include "../src/input_buffer.h"

static void perform_meta_command_when_exiting_then_returns_exit()
{
    InputBuffer *input_buffer = new_input_buffer();
    input_buffer->buffer = ".exit";
    MetaCommandResult command = perform_meta_command(input_buffer);
    assert_int_equal(META_COMMAND_EXIT, command);
}

static void perform_meta_command_when_invalid_input_then_returns_unrecognized()
{
    InputBuffer *input_buffer = new_input_buffer();
    input_buffer->buffer = "some invalid command";
    MetaCommandResult command = perform_meta_command(input_buffer);
    assert_int_equal(META_COMMAND_UNRECOGNIZED_COMMAND, command);
}