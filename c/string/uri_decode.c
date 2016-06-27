#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* uri_decode(char* in_str) {
	char *out_str;
	out_str = (char*) malloc(1);
	int on_ch = 0;

	// Loop through input string
	while (on_ch < strlen(in_str)) {
		// Add character to output per every input run
		out_str = (char*) realloc(out_str, 1);
		switch(in_str[on_ch]) {
			case '%': // This is special, so handle carefully
				// If it's another %
				if (in_str[on_ch + 1] == '%') {
					sprintf(out_str, "%s%%", out_str);
					// Skip one character
					on_ch++;
				}
				else { // Decode the string
					char ascii_bit[2];
					ascii_bit[0] = in_str[on_ch+1];
					ascii_bit[1] = in_str[on_ch+2];
					// Convert to decimal & print output
					int no_res = (int)strtol(ascii_bit, NULL, 16);
					sprintf(out_str, "%s%c", out_str, no_res);
					// Skip two characters
					on_ch = on_ch + 2;
				}
				break;
			case '+': // Decode this to a space
				sprintf(out_str, "%s ", out_str);
				break;
			default: // Just add the character if it's not special
				sprintf(out_str, "%s%c", out_str, in_str[on_ch]);
				break;
		}
		on_ch++;
	}

	return out_str;
}

int main(int argc, char *argv[]) {
	char* output = uri_decode(argv[1]);
	printf("%s\n", output);
	free(output);
	return 0;
}
