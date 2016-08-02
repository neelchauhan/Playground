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

void init_benc_tree(struct BencodeTree **tree, int type);

void init_string(struct BencodeTree **tree, char *str);

void free_benc_tree(struct BencodeTree **tree);
