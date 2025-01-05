#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

void parse_content(char *content) {
    char buffer[128];  
    size_t content_length = strlen(content);

    if (content_length < 10) {
        printf("Content too short to parse.\n");
        return;
    }

    char *token = strtok(content, ";");

    while (token != NULL) {
        strcpy(buffer, token); 
        printf("Processed token: %s\n", buffer);
        token = strtok(NULL, ";");  
    }
}

void parse_metadata(char *content) {
    char metadata[32];  
    size_t content_length = strlen(content);
    
    if (content_length >= 32) {
        strncpy(metadata, content, 31);  
        metadata[31] = '\0';  
    } else {
        strcpy(metadata, content);
    }

    // Simulate different types of metadata being parsed
    if (strstr(metadata, "version") != NULL) {
        printf("Found version information in metadata.\n");
    }

    if (strstr(metadata, "author") != NULL) {
        printf("Found author information in metadata.\n");
    }

    printf("Metadata parsed: %s\n", metadata);
}

