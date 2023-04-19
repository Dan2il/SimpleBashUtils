#ifndef SRC_GREP_PROCESSING_FLAGS_H_
#define SRC_GREP_PROCESSING_FLAGS_H_

#include "list.h"

void FormCFlag(OPTION_STATUS *option_status);
void FormEFlag(int argc, const char **argv, const char *word, int *counter_for_argc, \
    size_t *counter_for_word, int *cflags_for_regcomp, OPTION_STATUS *option_status, \
        struct NODE_FOR_REGEX *null_node_for_regex);
int FormFFlag(int argc, const char **argv, const char *word, int *counter_for_argc, \
    size_t *counter_for_word, int *cflags_for_regcomp, OPTION_STATUS *option_status, \
        struct NODE_FOR_REGEX *null_node_for_regex);
void FormHFlag(OPTION_STATUS *option_status);
void FormIFlag(OPTION_STATUS *option_status);
void FormLFlag(OPTION_STATUS *option_status);
void FormNFlag(OPTION_STATUS *option_status);
void FormOFlag(OPTION_STATUS *option_status);
void FormSFlag(OPTION_STATUS *option_status);
void FormVFlag(OPTION_STATUS *option_status);

void ReadFRegexFile(struct NODE_FOR_REGEX *null_node_for_regex, \
                        FILE *file_witn_regex, int *check_empty, int *cflags_for_regcomp);

#endif  // SRC_GREP_PROCESSING_FLAGS_H_
