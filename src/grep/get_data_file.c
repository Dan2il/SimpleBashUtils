#include "get_data_file.h"

void CheckOpenFile(struct NODE_FOR_NAME_FILE *null_node_for_name_file) {
    for (struct NODE_FOR_NAME_FILE *adress_file_name = null_node_for_name_file->next_node_for_name_file; \
            adress_file_name != NULL; adress_file_name = adress_file_name->next_node_for_name_file) {
        FILE *data = fopen(adress_file_name->file_name, "r");
        if (!data) {
            null_node_for_name_file->size_list--;
        }
    }
}

int CheckMoreRegex(OPTION_STATUS *option_status, struct NODE_FOR_REGEX *null_node_for_regex, \
            const char *line) {
    int counter_true_regex = 0;
    for (struct NODE_FOR_REGEX *adress_for_regex = null_node_for_regex->next_node_for_regex; \
            adress_for_regex != NULL; adress_for_regex = adress_for_regex->next_node_for_regex) {
        regex_t regular_expressions = adress_for_regex->regular_expressions;
        int check_error_for_regexec = regexec(&regular_expressions, line, 0, &option_status->regmatch, 0);
        if (!check_error_for_regexec) {
            counter_true_regex++;
        }
        char errbuf[1024];
        regerror(check_error_for_regexec, &regular_expressions, errbuf, 1024);
    }
    return counter_true_regex;
}

void GetDataFromFile(OPTION_STATUS *option_status, struct NODE_FOR_REGEX *null_node_for_regex, \
        struct NODE_FOR_NAME_FILE *null_node_for_name_file) {
    CheckOpenFile(null_node_for_name_file);
    for (struct NODE_FOR_NAME_FILE *adress_file_name = null_node_for_name_file->next_node_for_name_file; \
                adress_file_name != NULL; adress_file_name = adress_file_name->next_node_for_name_file) {
        FILE *data = fopen(adress_file_name->file_name, "r");
        if (!data) {
            if (option_status->s_option_status == 0) {
                fprintf(stderr, "s21_grep: %s: ", adress_file_name->file_name);
                // perror("");
            }
        } else {
            int counter_lines = 0;
            int counter_line_check = 0;
            int check_empty_line = 0;
            ReadFile(data, option_status, null_node_for_regex, null_node_for_name_file, \
                        adress_file_name, &counter_lines, &counter_line_check, &check_empty_line);
            PrintCLFFlags(option_status, null_node_for_name_file, adress_file_name, \
                    null_node_for_regex, counter_line_check, counter_lines);
            if (option_status->l_option_status && null_node_for_regex->check_error_f_flag && \
                    !option_status->h_option_status) {
                printf("%s\n", adress_file_name->file_name);
            }
        }
        if (data) {
            fclose(data);
        }
    }
}

void ReadFile(FILE *data, OPTION_STATUS *option_status, struct NODE_FOR_REGEX *null_node_for_regex, \
        struct NODE_FOR_NAME_FILE *null_node_for_name_file, struct NODE_FOR_NAME_FILE *adress_file_name, \
            int *counter_lines, int *counter_line_check, int *check_empty_line) {
    while (feof(data) == 0) {
        char *line = NULL;
        line = GetLine(data);
        *counter_lines += 1;
        int get_search = 0;
        if (!null_node_for_regex->check_error_f_flag \
                || (option_status->v_option_status && null_node_for_regex->check_error_f_flag)) {
            if (!option_status->o_option_status || \
                    (option_status->o_option_status && option_status->c_option_status) \
                            || (option_status->o_option_status && option_status->l_option_status) \
                                || (option_status->o_option_status && option_status->v_option_status)) {
                get_search = CheckMoreRegex(option_status, null_node_for_regex, line);
                if (feof(data) != 0 && ((!(get_search && !option_status->v_option_status) \
                        && !(!get_search && option_status->v_option_status)) \
                            && !option_status->c_option_status)) {
                    free(line);
                    break;
                }
                if (((get_search && !option_status->v_option_status) \
                        || (!get_search && option_status->v_option_status)) \
                            && !option_status->c_option_status) {
                    if (!(feof(data) != 0 && line[0] == '\0')) {
                        PrintCheckString(option_status, adress_file_name, \
                                            null_node_for_name_file, line, *counter_lines);
                        *counter_line_check += 1;
                    }
                    if (option_status->l_option_status == 1) {
                        free(line);
                        break;
                    }
                } else if (((get_search && !option_status->v_option_status) \
                                || (!get_search && option_status->v_option_status)) \
                                    && option_status->c_option_status) {
                    *counter_line_check += 1;
                    if (*counter_lines == 1 && feof(data) != 0 && (line[0] == '\n' || line[0] == '\0')) {
                        *counter_line_check -= 1;
                    }
                }
                if (feof(data) != 0 && strlen(line) >= 1 && line[0] != '\n' \
                        && option_status->c_option_status == 0 && *check_empty_line \
                            && option_status->l_option_status == 0 && *counter_lines > 1 \
                                && *counter_line_check > 1) {
                    printf("\n");
                }
            } else {
                PrintCheckOflag(null_node_for_regex, null_node_for_name_file, \
                        adress_file_name, option_status, line, counter_line_check, counter_lines);
                if (feof(data) != 0 && strlen(line) >= 1 && line[0] != '\n' \
                        && option_status->c_option_status == 0 && *check_empty_line \
                            && option_status->l_option_status == 0 && *counter_lines > 1 \
                                && *counter_line_check > 1 && option_status->v_option_status) {
                    printf("\n");
                }
            }
        }
        if (line[0] == '\n') {
            *check_empty_line = 0;
        } else {
            *check_empty_line += 1;
        }
        free(line);
    }
}
