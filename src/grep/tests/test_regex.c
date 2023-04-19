
    
    struct NODE_FOR_NAME_FILE *next_node = (struct NODE_FOR_NAME_FILE*)malloc(sizeof(struct NODE_FOR_NAME_FILE));
    next_node->file_name = file_name;
    next_node->num_node_in_list = adress->num_node_in_list + 1;
