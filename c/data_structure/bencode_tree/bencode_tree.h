#include <stdio.h>
#include <stdlib.h>

#define IS_STRING 0
#define IS_INT 1
#define IS_LIST 2
#define IS_DICT 3

struct BencodeTree {
	int type;

	char *str_value;
	int int_value;
	struct BencodeTree *next; // To use if inside a list/dictionary
	struct BencodeTree *below;
};

void init_benc_tree(struct BencodeTree **tree, int type) {
	*tree = (struct BencodeTree*) malloc(sizeof(struct BencodeTree));
	(*tree)->type = type;
	(*tree)->str_value = NULL;
	(*tree)->next = NULL;
	(*tree)->below = NULL;
}

void free_benc_tree(struct BencodeTree **tree) {
	if ((*tree)->str_value != NULL) free((*tree)->str_value);
	if ((*tree)->next != NULL) free_benc_tree((&(*tree)->next));
	if ((*tree)->below != NULL) free_benc_tree((&(*tree)->below));
	free(*tree);
}

