#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *content = read_file(argv[1]);
    if (content == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    printf("toyparser 0.1\n");
    parse_content(content);
    parse_metadata(content);

    free(content);
    return 0;
}

