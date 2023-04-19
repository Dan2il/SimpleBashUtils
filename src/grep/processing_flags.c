#include "processing_flags.h"

void FormCFlag(OPTION_STATUS *option_status) {
    option_status->c_option_status = 1;
    option_status->flag_status = 1;
}

void FormEFlag(int argc, const char **argv, const char *word, int *counter_for_argc, \
                size_t *counter_for_word, int *cflags_for_regcomp, \
                    OPTION_STATUS *option_status, struct NODE_FOR_REGEX *null_node_for_regex) {
    option_status->e_option_status = 1;
    option_status->flag_status = 1;
    if (word[*counter_for_word + 1] != '\0') {
        int size_pattern = strlen(word) - *counter_for_word;
        char *pattern = (char*)malloc(size_pattern * sizeof(char));
        *counter_for_word += 1;
        for (int counter_for_buffer = 0; word[*counter_for_word] != '\0'; ) {
            pattern[counter_for_buffer] = word[*counter_for_word];
            ++counter_for_buffer;
            *counter_for_word += 1;
        }
        RegcompPushRegexForChar(null_node_for_regex, pattern, cflags_for_regcomp);
        option_status->regex_status++;
        free(pattern);
    } else {
        *counter_for_argc += 1;
        if (*counter_for_argc < argc) {
            RegcompPushRegexForChar(null_node_for_regex, (char*)argv[*counter_for_argc], cflags_for_regcomp);
            option_status->regex_status++;
        } else {
            *counter_for_argc -= 1;
        }
    }
}

int FormFFlag(int argc, const char **argv, const char *word, int *counter_for_argc, \
                size_t *counter_for_word, int *cflags_for_regcomp, \
                    OPTION_STATUS *option_status, struct NODE_FOR_REGEX *null_node_for_regex) {
    option_status->f_option_status = 1;
    option_status->flag_status = 1;
    int check_empty = 0;
    if (word[*counter_for_word + 1] != '\0') {
        int size_pattern = strlen(word) - *counter_for_word;
        char *file_name = (char*)malloc(size_pattern * sizeof(char));
        *counter_for_word += 1;
        for (int counter_for_buffer = 0; word[*counter_for_word]  != '\0';) {
            file_name[counter_for_buffer] = word[*counter_for_word];
            ++counter_for_buffer;
            *counter_for_word += 1;
        }
        FILE *file_witn_regex = fopen(file_name, "r");
        ReadFRegexFile(null_node_for_regex, file_witn_regex, &check_empty, cflags_for_regcomp);
        if (file_witn_regex) {
            fclose(file_witn_regex);
        }
        free(file_name);
        option_status->regex_status++;
    } else {
        *counter_for_argc += 1;
            if (*counter_for_argc < argc) {
            FILE *file_witn_regex = fopen(argv[*counter_for_argc], "r");
            ReadFRegexFile(null_node_for_regex, file_witn_regex, &check_empty, cflags_for_regcomp);
            if (file_witn_regex) {
                fclose(file_witn_regex);
            }
            option_status->regex_status++;
        } else {
            *counter_for_argc -= 1;
        }
    }
    return check_empty;
}

void ReadFRegexFile(struct NODE_FOR_REGEX *null_node_for_regex, FILE *file_witn_regex, \
                        int *check_empty, int *cflags_for_regcomp) {
    if (file_witn_regex != NULL) {
        while (!feof(file_witn_regex)) {
        // for ( ; feof(file_witn_regex) == 0; ) {
            char *text_for_regex = GetLine(file_witn_regex);
            if ((text_for_regex[0] == '\0' || text_for_regex[0] == '\n') && feof(file_witn_regex) == 0) {
                if (*check_empty) {
                    null_node_for_regex->check_error_f_flag = 1;
                }
                free(text_for_regex);
                break;
            }
            int size_regex = strlen(text_for_regex);
            if (size_regex > 0) {
                if (text_for_regex[--size_regex] == '\n') {
                    text_for_regex[size_regex] = '\0';
                }
            }
            if (size_regex > 0) {
                RegcompPushRegexForChar(null_node_for_regex, text_for_regex, cflags_for_regcomp);
            }
            *check_empty += 1;
            free(text_for_regex);
        }
    }
}

void FormHFlag(OPTION_STATUS *option_status) {
    option_status->h_option_status = 1;
    option_status->flag_status = 1;
}

void FormIFlag(OPTION_STATUS *option_status) {
    option_status->i_option_status = 1;
    option_status->flag_status = 1;
}

void FormLFlag(OPTION_STATUS *option_status) {
    option_status->l_option_status = 1;
    option_status->flag_status = 1;
}

void FormNFlag(OPTION_STATUS *option_status) {
    option_status->n_option_status = 1;
    option_status->flag_status = 1;
}

void FormOFlag(OPTION_STATUS *option_status) {
    option_status->o_option_status = 1;
    option_status->flag_status = 1;
}

void FormSFlag(OPTION_STATUS *option_status) {
    option_status->s_option_status = 1;
    option_status->flag_status = 1;
}

void FormVFlag(OPTION_STATUS *option_status) {
    option_status->v_option_status = 1;
    option_status->flag_status = 1;
}
