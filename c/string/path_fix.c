#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fix_path(char *in_str, char **out_str) {
	char *proc_str = (char*) malloc(1);
	char last_ch = (char) NULL;

	// Loop through input string
	for (int on_ch = 0; on_ch < strlen(in_str); on_ch++) {
		if ((in_str[on_ch] == last_ch) && (last_ch == '/')) {}
		else {
			proc_str = (char*) realloc(proc_str, 1);
			sprintf(proc_str, "%s%c", proc_str, in_str[on_ch]);
		}
		last_ch = in_str[on_ch];
	}

	*out_str = proc_str;
}

int main(int argc, char *argv[]) {
	char* output;
	fix_path(argv[1], &output);
	printf("%s\n", output);
	free(output);
	return 0;
}
