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

void free_benc_tree(struct BencodeTree **tree) {
	if ((*tree)->str_value != NULL) free((*tree)->str_value);
	if ((*tree)->next != NULL) free_benc_tree((&(*tree)->next));
	if ((*tree)->below != NULL) free_benc_tree((&(*tree)->below));
	free(*tree);
}

