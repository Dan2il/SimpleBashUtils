#ifndef SRC_GREP_OUT_FUNCTIONS_H_
#define SRC_GREP_OUT_FUNCTIONS_H_

#include "grep.h"

char* GetLine(FILE *data);
void PrintCheckString(const OPTION_STATUS *option_status, \
    const struct NODE_FOR_NAME_FILE *adress_file_name, \
        const struct NODE_FOR_NAME_FILE *null_node_for_name_file, \
            const char *line, const int counter_for_line);
void PrintCheckCFlag(const struct NODE_FOR_NAME_FILE *null_node_for_name_file, \
    const struct NODE_FOR_NAME_FILE *adress_file_name, const OPTION_STATUS *option_status, \
        const int counter_line_check);
void PrintCheckOflag(struct NODE_FOR_REGEX *null_node_for_regex, \
    struct NODE_FOR_NAME_FILE *null_node_for_name_file, struct NODE_FOR_NAME_FILE *adress_file_name, \
        OPTION_STATUS *option_status, char *line, int *counter_line_check, int *counter_lines);
void PrintCLFFlags(const OPTION_STATUS *option_status, \
    const struct NODE_FOR_NAME_FILE *null_node_for_name_file, \
        const struct NODE_FOR_NAME_FILE *adress_file_name, \
            const struct NODE_FOR_REGEX *null_node_for_regex, int counter_line_check, int counter_lines);

#endif  // SRC_GREP_OUT_FUNCTIONS_H_
