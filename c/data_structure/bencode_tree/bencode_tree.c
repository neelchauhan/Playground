#include "bencode_tree.h"

#include <math.h>
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
}

void add_int_to_list(struct BencodeTree **tree, int number) {
	struct BencodeTree *int_obj;
	init_benc_tree(&int_obj, IS_INT);
	int_obj->int_value = number;
	add_obj_to_list(tree, &int_obj);
}

void add_obj_to_dict(struct BencodeTree **tree, char *key, struct BencodeTree **add_obj) {
	add_string_to_list(tree, key);
	add_obj_to_list(tree, add_obj);
}

void output_benc_str(struct BencodeTree **tree, char **out_str) {
	*out_str = (char *) malloc(1);
	struct BencodeTree *curr_item = *tree;
	while (curr_item != NULL) {
		switch (curr_item->type) {
			case IS_STRING:
				; // Necessary because I can't define a variable at the beginning of a 'case'
				size_t str_len = strlen(curr_item->str_value);
				size_t int_dig = floor(log10(abs(str_len)));
				*out_str = (char *) realloc(*out_str, str_len + int_dig + 1);
				sprintf(*out_str, "%zd:%s", str_len, curr_item->str_value);
				break;
			default:
				break;
		}
		curr_item = curr_item->next;
	}
}

void free_benc_tree(struct BencodeTree **tree) {
	if ((*tree)->str_value != NULL) free((*tree)->str_value);
	if ((*tree)->next != NULL) free_benc_tree((&(*tree)->next));
	if ((*tree)->below != NULL) free_benc_tree((&(*tree)->below));
	free(*tree);
}

