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

void add_obj_to_list(struct BencodeTree **tree, struct BencodeTree **add_obj);

void add_string_to_list(struct BencodeTree **tree, char *str);

void add_int_to_list(struct BencodeTree **tree, int number);

void add_obj_to_dict(struct BencodeTree **tree, char *key, struct BencodeTree **add_obj);

void output_benc_str(struct BencodeTree **tree, char **out_str);

void free_benc_tree(struct BencodeTree **tree);
