#include "bencode_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	struct BencodeTree *root;
	init_benc_tree(&root, IS_STRING);
	init_string(&root, "Hello!");

	printf("%d\n", root->type);
	printf("%s\n", root->str_value);
	free_benc_tree(&root);
	return 0;
}
