#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	unsigned int chars = 0, words = 0, lines = 0;
	FILE *f = fopen(argv[2], "r");
	char ch;
	int in_word;

	while ((ch = fgetc(f)) != EOF) {
		chars++;
		if (isspace(ch)) {
			in_word = 0;
		} else {
			if (!in_word) {
				words++;
				in_word = 1;
			}
		}
		if (ch == '\n')
			lines++;
	}
	if (!(strcmp(argv[1], "-w")))
		printf("\t%u\n", words);
	else if (!(strcmp(argv[1], "-l")))
		printf("\t%u\n", lines);
	else if (!(strcmp(argv[1], "-c")))
		printf("\t%u\n", chars);
	else
		printf("\t%u %u %u\n", lines, words, chars);

	return 0;
}
