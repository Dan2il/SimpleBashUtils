#ifndef SRC_GREP_PARSING_H_
#define SRC_GREP_PARSING_H_

#include "processing_flags.h"

int Parser(int argc, char **argv, OPTION_STATUS *option_status, \
            struct NODE_FOR_REGEX *null_node_for_regex, struct NODE_FOR_NAME_FILE *null_node_for_name_file);
void ParserForWords(int argc, char **argv, char *word, int *counter_for_argc, int *cflags_for_regcomp, \
                        OPTION_STATUS *option_status, const OPTION_FLAGS *option_flags, \
                            struct NODE_FOR_REGEX *null_node_for_regex, int *position, int *options_check);
void SearchIFlag(const char *word, int *cflags_for_regcomp, OPTION_STATUS *option_status, \
    const OPTION_FLAGS *option_flags);

#endif  // SRC_GREP_PARSING_H_
