#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

#include <stdlib.h>

typedef struct
{
    char *buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer *new_input_buffer();
void free_input_buffer(InputBuffer *input_buffer);
void read_input(InputBuffer *input_buffer);

#endif