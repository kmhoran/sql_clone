#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include "input_buffer.h"
#include "enums.h"

void print_prompt();

MetaCommandResult perform_meta_command(InputBuffer *input_buffer);

#endif