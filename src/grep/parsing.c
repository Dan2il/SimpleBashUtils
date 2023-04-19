#include "parsing.h"

int Parser(int argc, char **argv, OPTION_STATUS *option_status, struct NODE_FOR_REGEX *null_node_for_regex, \
                struct NODE_FOR_NAME_FILE *null_node_for_name_file) {
    int counter_for_argc = 1;
    int cflags_for_regcomp = 0;
    int options_check = 0;
    const int num_for_line = 0;
    OPTION_FLAGS option_flags = InitializationStructOptionFlags();
    int *position = (int*)calloc(argc, sizeof(int));

    for ( ; counter_for_argc < argc; counter_for_argc++) {
        if (argv[counter_for_argc][num_for_line] == option_flags.dash_option_flag \
                && position[counter_for_argc] == 0) {
            SearchIFlag(argv[counter_for_argc], &cflags_for_regcomp, option_status, &option_flags);
        }
    }
    counter_for_argc = 1;
    for ( ; counter_for_argc < argc; counter_for_argc++) {
        if (argv[counter_for_argc][num_for_line] == option_flags.dash_option_flag \
                && position[counter_for_argc] == 0) {
            position[counter_for_argc] = 1;
            ParserForWords(argc, argv, argv[counter_for_argc], &counter_for_argc, &cflags_for_regcomp, \
                option_status, &option_flags, null_node_for_regex, position, &options_check);
        }
    }
    counter_for_argc = 1;
    for ( ; counter_for_argc < argc; counter_for_argc++) {
        if (argv[counter_for_argc][num_for_line] != option_flags.dash_option_flag \
                && position[counter_for_argc] == 0) {
            if (!options_check) {
                RegcompPushRegexForChar(null_node_for_regex, argv[counter_for_argc], &cflags_for_regcomp);
                options_check = 1;
            } else {
                PushBackListNamesFiles(null_node_for_name_file, argv[counter_for_argc]);
            }
        }
    }
    free(position);
    return cflags_for_regcomp;
}

void ParserForWords(int argc, char **argv, char *word, int *counter_for_argc, int *cflags_for_regcomp, \
                    OPTION_STATUS *option_status, const OPTION_FLAGS *option_flags, \
                        struct NODE_FOR_REGEX *null_node_for_regex, int *position, int *options_check) {
    for (size_t counter = 0; word[counter] != '\0'; counter++) {
        if (word[counter] == option_flags->i_option_flag) {
            FormIFlag(option_status);
            *cflags_for_regcomp = 2;
        }
        if (word[counter] == option_flags->c_option_flag) {
            FormCFlag(option_status);
        }
        if (word[counter] == option_flags->e_option_flag) {
            FormEFlag(argc, (const char**)argv, word, counter_for_argc, \
                        &counter, cflags_for_regcomp, option_status, null_node_for_regex);
            position[*counter_for_argc] = 1;
            *options_check += 1;
        }
        if (word[counter] == option_flags->f_option_flag) {
            FormFFlag(argc, (const char**)argv, word, counter_for_argc, \
                        &counter, cflags_for_regcomp, option_status, null_node_for_regex);
            position[*counter_for_argc] = 1;
            *options_check += 1;
        }
        if (word[counter] == option_flags->h_option_flag) {
            FormHFlag(option_status);
        }
        if (word[counter] == option_flags->l_option_flag) {
            FormLFlag(option_status);
        }
        if (word[counter] == option_flags->n_option_flag) {
            FormNFlag(option_status);
        }
        if (word[counter] == option_flags->o_option_flag) {
            FormOFlag(option_status);
        }
        if (word[counter] == option_flags->s_option_flag) {
            FormSFlag(option_status);
        }
        if (word[counter] == option_flags->v_option_flag) {
            FormVFlag(option_status);
        }
    }
}

void SearchIFlag(const char *word, int *cflags_for_regcomp, \
                    OPTION_STATUS *option_status, const OPTION_FLAGS *option_flags) {
    for (size_t counter = 0; word[counter] != '\0'; counter++) {
        if (word[counter] == option_flags->i_option_flag) {
            FormIFlag(option_status);
            *cflags_for_regcomp = 2;
        }
    }
}
