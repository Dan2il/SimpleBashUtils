#ifndef SRC_GREP_GREP_H_
#define SRC_GREP_GREP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct {
    int e_option_status;
    int i_option_status;
    int v_option_status;
    int c_option_status;
    int l_option_status;
    int n_option_status;
    int h_option_status;
    int s_option_status;
    int f_option_status;
    int o_option_status;
    regmatch_t regmatch;
    regex_t regular_expressions;
    int regex_status;
    int flag_status;
} OPTION_STATUS;

typedef struct {
    char e_option_flag;
    char i_option_flag;
    char v_option_flag;
    char c_option_flag;
    char l_option_flag;
    char n_option_flag;
    char h_option_flag;
    char s_option_flag;
    char f_option_flag;
    char o_option_flag;
    char dash_option_flag;
    regex_t regular_expressions;
    int regex_status;
} OPTION_FLAGS;

struct NODE_FOR_REGEX {
    struct NODE_FOR_REGEX *next_node_for_regex;
    regex_t regular_expressions;
    int size_list;
    int num_node_in_list;
    int check_error_f_flag;
};

struct NODE_FOR_NAME_FILE {
    struct NODE_FOR_NAME_FILE *next_node_for_name_file;
    char *file_name;
    int size_list;
    int num_node_in_list;
};

OPTION_FLAGS InitializationStructOptionFlags();
OPTION_STATUS InitializationStructOptionStatus();

int RegcompPushRegex(struct NODE_FOR_REGEX *null_node_for_regex, char **argv, \
                            int *counter_for_argc, int *cflags_for_regcomp);
void RegcompPushRegexForChar(struct NODE_FOR_REGEX *null_node_for_regex, \
                                char *text_for_regex, int *cflags_for_regcomp);

#endif  // SRC_GREP_GREP_H_
