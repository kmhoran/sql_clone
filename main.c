#include <stdio.h>
#include "input_buffer.h"

int main()
{
    InputBuffer *input_buffer = new_input_buffer();

    printf("Buffer length: %zu\n", input_buffer->buffer_length);
    printf("Input length: %zd\n", input_buffer->input_length);

    free_input_buffer(input_buffer);

    return 0;
}
