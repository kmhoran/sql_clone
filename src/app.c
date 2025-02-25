#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "input_buffer.h"
#include "utilities.h"
#include "enums.h"
#include "statement_parsing.h"

int run()
{
    InputBuffer *input_buffer = new_input_buffer();

    while (true)
    {
        print_prompt();
        read_input(input_buffer);

        if (input_buffer->buffer[0] == '.')
        {
            switch (perform_meta_command(input_buffer))
            {
            case (META_COMMAND_SUCCESS):
                continue;
            case (META_COMMAND_UNRECOGNIZED_COMMAND):
                printf("Unrecognized command: '%s'\n", input_buffer->buffer);
                continue;
            case (META_COMMAND_EXIT):
                return EXIT_SUCCESS;
            }
        }
        Statement statement;
        switch (prepare_statement(input_buffer, &statement))
        {
        case (PEPARE_SUCCESS):
            break;
        case (PREPARE_UNRECOGNIZED_STATEMENT):
            printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
            continue;
        }

        execute_statement(&statement);
        printf("Executed.\n");
        free_input_buffer(input_buffer);
    }
    return EXIT_SUCCESS;
}
