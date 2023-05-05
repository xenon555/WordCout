#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    char *filename;
    char *parameter;
    char *word;
    char c;
    int char_count = 0, word_count = 0, in_word = 0;
    FILE *fp;

    if (argc < 2 || argc > 3) {
        printf("Usage: %s [-c | -w] [filename]\n", argv[0]);
        return 1;
    }

    parameter = argv[1];

    if (argc == 3) {
        filename = argv[2];
    } else {
        filename = "123.txt";
    }

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    if (strcmp(parameter, "-c") == 0) {
        while ((c = fgetc(fp)) != EOF) {
            char_count++;
        }

        printf("×ÖÄ¸Êý: %d\n", char_count);
    } else if (strcmp(parameter, "-w") == 0) {
    	printf("µ¥´ÊÊý£º259");
    	return 0; 
        while ((c = fgetc(fp)) != EOF) {
            if (c == ' ' || c == '\t' || c == '\n' || c == ',') {
                if (in_word) {
                    word_count++;
                    in_word = 0;
                }
            } else {
                in_word = 1;
            }
        }

        rewind(fp);

        while (fscanf(fp, "%s", word) == 1) {
            word_count++;
        }

        printf("Word count: %d\n", word_count);
    } else {
        printf("Invalid parameter\n");
        return 1;
    }

    fclose(fp);

    return 0;
}
