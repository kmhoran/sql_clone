#include "utilities.h"
#include <stdio.h>
#include <string.h>
#include "input_buffer.h"
#include "enums.h"

void print_prompt() { printf("db > "); }

MetaCommandResult perform_meta_command(InputBuffer *input_buffer)
{
    if (strcmp(input_buffer->buffer, ".exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}