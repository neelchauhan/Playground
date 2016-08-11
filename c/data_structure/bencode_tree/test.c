#include "bencode_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	struct BencodeTree *root;
	char *out;
	init_benc_tree(&root, IS_STRING);
	init_string(&root, "Hello!");

	printf("%d\n", root->type);
	printf("%s\n", root->str_value);
	output_benc_str(&root, &out);
	printf("%s\n", out);
	free_benc_tree(&root);
	free(out);

	printf("\n");

	init_benc_tree(&root, IS_LIST);
	add_string_to_list(&root, "Hi!");
	printf("%d\n", root->type);
	printf("%s\n", root->below->str_value);
	output_benc_str(&root, &out);
	printf("%s\n", out);
	free_benc_tree(&root);
	free(out);
	return 0;
}
