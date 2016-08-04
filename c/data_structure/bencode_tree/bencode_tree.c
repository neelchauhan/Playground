#include "bencode_tree.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_benc_tree(struct BencodeTree **tree, int type) {
	*tree = (struct BencodeTree*) malloc(sizeof(struct BencodeTree));
	(*tree)->type = type;
	(*tree)->str_value = NULL;
	(*tree)->next = NULL;
	(*tree)->below = NULL;
}

void init_string(struct BencodeTree **tree, char *str) {
	(*tree)->str_value = (char *) malloc(strlen(str));
	strcpy((*tree)->str_value, str);
}

void add_obj_to_list(struct BencodeTree **tree, struct BencodeTree **add_obj) {
	if ((*tree)->below == NULL) (*tree)->below = *add_obj;
	else {
		struct BencodeTree *curr_obj = (*tree)->below;
		while (curr_obj->next != NULL) curr_obj = curr_obj->next;
		curr_obj->next = *add_obj;
	}
}

void add_string_to_list(struct BencodeTree **tree, char *str) {
	struct BencodeTree *str_obj;
	init_benc_tree(&str_obj, IS_STRING);
	init_string(&str_obj, str);
	add_obj_to_list(tree, &str_obj);

	//if ((*tree)->below == NULL) (*tree)->below = str_obj;
	//else {
	//	struct BencodeTree *curr_obj = (*tree)->below;
	//	while (curr_obj->next != NULL) curr_obj = curr_obj->next;
	//	curr_obj->next = str_obj;
	//}
}

void free_benc_tree(struct BencodeTree **tree) {
	if ((*tree)->str_value != NULL) free((*tree)->str_value);
	if ((*tree)->next != NULL) free_benc_tree((&(*tree)->next));
	if ((*tree)->below != NULL) free_benc_tree((&(*tree)->below));
	free(*tree);
}

