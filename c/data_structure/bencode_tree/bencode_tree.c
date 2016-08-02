#include "bencode_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *test_str = "Hello!";

	struct BencodeTree *root;
	init_benc_tree(&root, IS_STRING);
	root->str_value = malloc(strlen(test_str));
	strcpy(root->str_value, test_str);

	printf("%d\n", root->type);
	printf("%s\n", root->str_value);
	free_benc_tree(&root);
	return 0;
}
