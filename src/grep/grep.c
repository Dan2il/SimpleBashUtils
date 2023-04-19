#include "parsing.h"

int main(int argc, char **argv) {
    OPTION_STATUS option_status = InitializationStructOptionStatus();
    struct NODE_FOR_REGEX *null_node_for_regex = \
                (struct NODE_FOR_REGEX*)malloc(sizeof(struct NODE_FOR_REGEX));
    *null_node_for_regex = InitializationListForRegex();
    struct NODE_FOR_NAME_FILE *null_node_for_name_file = \
                    (struct NODE_FOR_NAME_FILE*)malloc(sizeof(struct NODE_FOR_NAME_FILE));
    *null_node_for_name_file = InitializationListForNameFile();
    Parser(argc, argv, &option_status, null_node_for_regex, null_node_for_name_file);
    GetDataFromFile(&option_status, null_node_for_regex, null_node_for_name_file);
    FreeListForRegex(null_node_for_regex);
    FreeListForNameFile(null_node_for_name_file);
}

int RegcompPushRegex(struct NODE_FOR_REGEX *null_node_for_regex, char **argv, \
                            int *counter_for_argc, int *cflags_for_regcomp) {
    regex_t regular_expressions;
    int for_check_error_in_regcomp = 0;
    for_check_error_in_regcomp = regcomp(&regular_expressions, argv[*counter_for_argc], *cflags_for_regcomp);
    if (for_check_error_in_regcomp != 0) {
        char buf[1024];
        regerror(for_check_error_in_regcomp, &regular_expressions, buf, 1024);
        fprintf(stderr, "%s\n", buf);
    }
    PushBackListRegexs(null_node_for_regex, &regular_expressions);
    *counter_for_argc += 1;
    return 1;
}

void RegcompPushRegexForChar(struct NODE_FOR_REGEX *null_node_for_regex, \
                                char *text_for_regex, int *cflags_for_regcomp) {
    regex_t regular_expressions;
    int for_check_error_in_regcomp = 0;
    for_check_error_in_regcomp = regcomp(&regular_expressions, text_for_regex, *cflags_for_regcomp);
    if (for_check_error_in_regcomp != 0) {
        char buf[1024];
        regerror(for_check_error_in_regcomp, &regular_expressions, buf, 1024);
        fprintf(stderr, "%s\n", buf);
    }
    PushBackListRegexs(null_node_for_regex, &regular_expressions);
}

OPTION_FLAGS InitializationStructOptionFlags() {
    OPTION_FLAGS option_flags;
    option_flags.c_option_flag = 'c';
    option_flags.e_option_flag = 'e';
    option_flags.f_option_flag = 'f';
    option_flags.h_option_flag = 'h';
    option_flags.i_option_flag = 'i';
    option_flags.l_option_flag = 'l';
    option_flags.n_option_flag = 'n';
    option_flags.o_option_flag = 'o';
    option_flags.s_option_flag = 's';
    option_flags.v_option_flag = 'v';
    option_flags.dash_option_flag = '-';
    option_flags.regex_status = 0;
return option_flags;
}

OPTION_STATUS InitializationStructOptionStatus() {
    OPTION_STATUS option_status;
    option_status.c_option_status = 0;
    option_status.e_option_status = 0;
    option_status.f_option_status = 0;
    option_status.h_option_status = 0;
    option_status.i_option_status = 0;
    option_status.l_option_status = 0;
    option_status.n_option_status = 0;
    option_status.o_option_status = 0;
    option_status.s_option_status = 0;
    option_status.v_option_status = 0;
    option_status.regex_status = 0;
    option_status.flag_status = 0;
return option_status;
}
