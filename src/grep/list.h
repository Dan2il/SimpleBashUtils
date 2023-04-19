#ifndef SRC_GREP_LIST_H_
#define SRC_GREP_LIST_H_

#include "get_data_file.h"

struct NODE_FOR_REGEX InitializationListForRegex();
struct NODE_FOR_NAME_FILE InitializationListForNameFile();

void FreeListForRegex(struct NODE_FOR_REGEX *null_node_for_regex);
void FreeListForNameFile(struct NODE_FOR_NAME_FILE *null_node_for_name_file);

void PushBackListRegexs(struct NODE_FOR_REGEX *null_node_for_regex, const regex_t *regular_expressions);
void PushBackListNamesFiles(struct NODE_FOR_NAME_FILE *null_node_for_name_file, char *file_name);

#endif  // SRC_GREP_LIST_H_
