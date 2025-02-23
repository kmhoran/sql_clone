#ifndef ENUMS_H
#define ENUMS_H

typedef enum
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND,
    META_COMMAND_EXIT
} MetaCommandResult;

typedef enum
{
    PEPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

#endif