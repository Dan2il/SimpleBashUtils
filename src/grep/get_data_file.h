#ifndef SRC_GREP_GET_DATA_FILE_H_
#define SRC_GREP_GET_DATA_FILE_H_

#include "out_functions.h"

struct CHECKING {
    int counter_line_check;
    int counter_all_true;
};

void GetDataFromFile(OPTION_STATUS *option_status, struct NODE_FOR_REGEX *null_node_for_regex, \
    struct NODE_FOR_NAME_FILE *null_node_for_name_file);
void CheckOpenFile(struct NODE_FOR_NAME_FILE *null_node_for_name_file);
int CheckMoreRegex(OPTION_STATUS *option_status, \
    struct NODE_FOR_REGEX *null_node_for_regex, const char *line);
void ReadFile(FILE *data, OPTION_STATUS *option_status, struct NODE_FOR_REGEX *null_node_for_regex, \
    struct NODE_FOR_NAME_FILE *null_node_for_name_file, struct NODE_FOR_NAME_FILE *adress_file_name, \
        int *counter_lines, int *counter_line_check, int *check_empty_line);

#endif  // SRC_GREP_GET_DATA_FILE_H_
