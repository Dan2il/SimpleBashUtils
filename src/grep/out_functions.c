#include "out_functions.h"

void PrintCheckString(const OPTION_STATUS *option_status, \
                        const struct NODE_FOR_NAME_FILE *adress_file_name, \
                            const struct NODE_FOR_NAME_FILE *null_node_for_name_file, \
                            const char *line, const int counter_for_line) {
    if (option_status->l_option_status) {
        printf("%s\n", adress_file_name->file_name);
    } else {
        if (null_node_for_name_file->size_list > 1 && option_status->h_option_status == 0) {
            printf("%s:", adress_file_name->file_name);
        }
        if (option_status->n_option_status == 1) {
            printf("%d:", counter_for_line);
        }
        if (option_status->o_option_status == 0 || \
                (option_status->o_option_status && option_status->v_option_status)) {
            printf("%s", line);
        }
    }
}

void PrintCLFFlags(const OPTION_STATUS *option_status, \
                    const struct NODE_FOR_NAME_FILE *null_node_for_name_file, \
                        const struct NODE_FOR_NAME_FILE *adress_file_name, \
                            const struct NODE_FOR_REGEX *null_node_for_regex, \
                                int counter_line_check, int counter_lines) {
    if (option_status->c_option_status == 1 && !null_node_for_regex->check_error_f_flag) {
        if (counter_line_check != counter_lines && option_status->v_option_status && \
            (adress_file_name->next_node_for_name_file != NULL \
                || null_node_for_name_file->size_list == 1)) {
            --counter_line_check;
        }
        if (option_status->l_option_status == 0) {
            PrintCheckCFlag(null_node_for_name_file, adress_file_name, option_status, counter_line_check);
        } else {
            int checc_for_c_and_l = 1;
            if (!counter_line_check) {
                checc_for_c_and_l = 0;
            }
            if (null_node_for_name_file->size_list > 1 && !option_status->h_option_status) {
                printf("%s:%d\n", adress_file_name->file_name, checc_for_c_and_l);
                if (checc_for_c_and_l) {
                    printf("%s\n", adress_file_name->file_name);
                }
            } else {
                printf("%d\n", checc_for_c_and_l);
                if ((option_status->h_option_status && checc_for_c_and_l) \
                        || (!option_status->h_option_status)) {
                    printf("%s\n", adress_file_name->file_name);
                }
            }
        }
    } else if (option_status->c_option_status == 1 && null_node_for_regex->check_error_f_flag) {
        if (option_status->l_option_status == 0) {
            if (adress_file_name->next_node_for_name_file != NULL \
                || null_node_for_name_file->size_list == 1) {
                --counter_lines;
            }
            if (null_node_for_name_file->size_list > 1 && !option_status->h_option_status) {
                printf("%s:", adress_file_name->file_name);
            }
            printf("%d\n", counter_lines);
        }
    }
}


void PrintCheckCFlag(const struct NODE_FOR_NAME_FILE *null_node_for_name_file, \
            const struct NODE_FOR_NAME_FILE *adress_file_name, \
                const OPTION_STATUS *option_status, const int counter_line_check) {
    if (null_node_for_name_file->size_list > 1 && option_status->h_option_status == 0) {
        printf("%s:", adress_file_name->file_name);
    }
    if (!option_status->v_option_status) {
        printf("%d\n", counter_line_check);
    } else {
        printf("%d\n", counter_line_check);
    }
}

char* GetLine(FILE *data) {
    int size_line = 2;
    char *line = (char*)malloc(size_line * sizeof(char));
    line[0] = '\0';
    if (feof(data) == 0) {
        for (int counter_for_line = 0; feof(data) == 0; counter_for_line++) {
            char sign = '\0';
            int check_fread = fread(&sign, sizeof(char), 1, data);
            if (check_fread != 0) {
                size_line += 1;
                char *buffer = realloc(line, size_line);
                if (NULL != buffer) {
                    line = buffer;
                }
                line[counter_for_line] = sign;
            }
            line[counter_for_line + 1] = '\0';
            if (sign == '\n') {
                counter_for_line++;
                line[counter_for_line] = '\0';
                break;
            }
        }
    } else {
        line[0] = '\0';
    }
    return line;
}

void PrintCheckOflag(struct NODE_FOR_REGEX *null_node_for_regex, \
    struct NODE_FOR_NAME_FILE *null_node_for_name_file, struct NODE_FOR_NAME_FILE *adress_file_name, \
        OPTION_STATUS *option_status, char *line, int *counter_line_check, int *counter_lines) {
    unsigned int maxMatches = strlen(line);
    unsigned int maxGroups = maxMatches + 1;
    regmatch_t *groupArray = (regmatch_t*)malloc(maxGroups * sizeof(regmatch_t));
    // regmatch_t groupArray[maxGroups];
    char *cursor = line;
    int flag_print_n = 0;
    int flag_print_name = 0;
    int i_flags = 0;
    if (option_status->i_option_status) {
        i_flags = 2;
    }

    for (struct NODE_FOR_REGEX *adress_for_regex = \
                        null_node_for_regex->next_node_for_regex; \
            adress_for_regex != NULL; adress_for_regex = adress_for_regex->next_node_for_regex) {
        if (option_status->f_option_status) {
            cursor = line;
        }
        unsigned int counter_for_o = 0;
        for ( ; counter_for_o < maxMatches; ++counter_for_o) {
            int get_search_o_flag = \
                    regexec(&adress_for_regex->regular_expressions, cursor, maxGroups, groupArray, i_flags);
            if ((!get_search_o_flag && !option_status->v_option_status) \
                    || (get_search_o_flag && option_status->v_option_status)) {
                *counter_line_check += 1;
                if ((option_status->c_option_status || null_node_for_name_file->size_list > 1) \
                        && flag_print_name == 0 && option_status->h_option_status == 0) {
                    printf("%s:", adress_file_name->file_name);
                    flag_print_name = 1;
                }
                if (option_status->n_option_status && flag_print_n == 0 \
                        && option_status->h_option_status == 0) {
                    printf("%d:", *counter_lines);
                    flag_print_n = 1;
                }
                if (!get_search_o_flag && !option_status->v_option_status) {
                    unsigned int offset = 0;
                    for (unsigned int counter_regmatch_t = 0; \
                            counter_regmatch_t < maxGroups; counter_regmatch_t++) {
                        if (groupArray[counter_regmatch_t].rm_so != -1) {
                            if (counter_regmatch_t == 0) {
                                offset = groupArray[counter_regmatch_t].rm_eo;
                            }
                            char *cursorCopy = (char*)malloc((strlen(cursor) + 1) * sizeof(char));
                            strcpy(cursorCopy, cursor);
                            cursorCopy[groupArray[counter_regmatch_t].rm_eo] = 0;
                            printf("%s\n", cursorCopy + groupArray[counter_regmatch_t].rm_so);
                            free(cursorCopy);
                        }
                    }
                    cursor += offset;
                } else if (get_search_o_flag && option_status->v_option_status) {
                    printf("%s", line);
                    break;
                }
            }
        }
    }
    free(groupArray);
}
