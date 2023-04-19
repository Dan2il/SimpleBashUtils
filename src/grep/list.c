#include "list.h"

struct NODE_FOR_REGEX InitializationListForRegex() {
    struct NODE_FOR_REGEX null_node_for_regex;
    null_node_for_regex.next_node_for_regex = NULL;
    null_node_for_regex.num_node_in_list = 0;
    null_node_for_regex.size_list = 0;
    null_node_for_regex.check_error_f_flag = 0;
    return null_node_for_regex;
}

struct NODE_FOR_NAME_FILE InitializationListForNameFile() {
    struct NODE_FOR_NAME_FILE null_node_for_name_file;
    char *text = "It is null node for name file";
    null_node_for_name_file.next_node_for_name_file = NULL;
    null_node_for_name_file.num_node_in_list = 0;
    null_node_for_name_file.size_list = 0;
    null_node_for_name_file.file_name = text;
    return null_node_for_name_file;
}

void FreeListForRegex(struct NODE_FOR_REGEX *null_node_for_regex) {
    struct NODE_FOR_REGEX *free_regex = null_node_for_regex;
    int skip_regex_in_null_node = 0;
    while (free_regex != NULL) {
        if (skip_regex_in_null_node != 0) {
            regfree(&free_regex->regular_expressions);
        }
        ++skip_regex_in_null_node;
        free_regex = free_regex->next_node_for_regex;
    }

    while (null_node_for_regex != NULL) {
        struct NODE_FOR_REGEX *free_node = null_node_for_regex;
        null_node_for_regex = null_node_for_regex->next_node_for_regex;
        free(free_node);
    }
}

void FreeListForNameFile(struct NODE_FOR_NAME_FILE *null_node_for_name_file) {
    while (null_node_for_name_file != NULL) {
        struct NODE_FOR_NAME_FILE *for_free = null_node_for_name_file;
        null_node_for_name_file = null_node_for_name_file->next_node_for_name_file;
        free(for_free);
    }
}

void PushBackListRegexs(struct NODE_FOR_REGEX *null_node_for_regex, const regex_t *regular_expressions) {
    struct NODE_FOR_REGEX *adress = null_node_for_regex;

    while (adress->next_node_for_regex != NULL) {
        adress = adress->next_node_for_regex;
    }

    struct NODE_FOR_REGEX *next_node = (struct NODE_FOR_REGEX*)malloc(sizeof(struct NODE_FOR_REGEX));
    next_node->next_node_for_regex = NULL;
    next_node->num_node_in_list = adress->num_node_in_list + 1;
    next_node->regular_expressions = *regular_expressions;
    null_node_for_regex->size_list++;
    next_node->size_list = null_node_for_regex->size_list;
    adress->next_node_for_regex = next_node;
}

void PushBackListNamesFiles(struct NODE_FOR_NAME_FILE *null_node_for_name_file, char *file_name) {
    struct NODE_FOR_NAME_FILE *adress = null_node_for_name_file;
    while (adress->next_node_for_name_file != NULL) {
        adress = adress->next_node_for_name_file;
    }
    struct NODE_FOR_NAME_FILE *next_node = \
                    (struct NODE_FOR_NAME_FILE*)malloc(sizeof(struct NODE_FOR_NAME_FILE));
    next_node->file_name = file_name;
    next_node->next_node_for_name_file = NULL;
    next_node->num_node_in_list = adress->num_node_in_list + 1;
    null_node_for_name_file->size_list++;
    next_node->size_list = null_node_for_name_file->size_list;
    adress->next_node_for_name_file = next_node;
}
