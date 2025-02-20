#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "input_buffer.h"
#include "utilities.h"

int main()
{
    InputBuffer *input_buffer = new_input_buffer();

    while (true)
    {
        print_prompt();
        read_input(input_buffer);

        if (strcmp(input_buffer->buffer, ".exit") == 0)
        {
            free_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Unrecognized command: '%s'.\n", input_buffer->buffer);
        }
    }
}
