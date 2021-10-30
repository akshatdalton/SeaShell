#include "utils.h"

#include "prompt.h"

char **tokenize(char *line, char delim) {
    char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
    char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
    int i, tokenIndex = 0, tokenNo = 0;

    for (i = 0; i < strlen(line); i++) {
        char readChar = line[i];
        if (readChar == delim) {
            token[tokenIndex] = '\0';
            if (tokenIndex != 0) {
                token = trim(token, ' ');
                token = trim(token, '\n');
                tokens[tokenNo] = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
                strcpy(tokens[tokenNo++], token);
                tokenIndex = 0;
            }
        } else {
            if (readChar != '\n' && readChar != '\t') {
                token[tokenIndex++] = readChar;
            }
        }
    }

    if (tokenIndex != 0) {
        // This means that we are at the end of the
        // string and it has not been copied yet.
        token[tokenIndex] = '\0';
        token = trim(token, ' ');
        token = trim(token, '\n');
        tokens[tokenNo] = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
        strcpy(tokens[tokenNo++], token);
    }
    // TODO: free(token) gives error here. Need to debug for it.
    tokens[tokenNo] = NULL;
    return tokens;
}

void destroy_tokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
}

char *concat(char *str1, char *str2) {
    // strcat using pointers.
    char *res = malloc(strlen(str1) + strlen(str2) + 1);
    int i = 0, curr_pos = 0;
    while (str1[i] != '\0') {
        res[curr_pos++] = str1[i++];
    }
    i = 0;
    while (str2[i] != '\0') {
        res[curr_pos++] = str2[i++];
    }
    return res;
}

char *trim(char *str, char ch) {
    // This function behaves same as the python/js trim function.
    // We don't modifiy the original pointer so that we can later free the memory.

    char *t = str;
    while (*t == ch) {
        t++;
    }

    for (int i = strlen(t) - 1; t[i] == ch; i--) {
        t[i] = '\0';
    }

    return t;
}

void exit_shell() {
    printf("\nClosed all Background processes\n");
    exit(0);
}

char *substr(const char *str, int start_ind, size_t length) {
    size_t total_length = strlen(str);
    if (start_ind + length > total_length) {
        return NULL;
    }

    char *child_str;
    child_str = (char *)malloc(sizeof(char) * (length + 1));

    for (int ind = 0; ind < length; ind++) {
        child_str[ind] = str[ind + start_ind];
    }
    child_str[length] = '\0';

    return child_str;
}
