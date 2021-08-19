#include "utils.h"

#include "prompt.h"

void initialize_everything() {
    printf(ANSI_CLEAR);
    printf(ANSI_YELLOW_BOLD "\n\t***\tWelcome to SeaShell\t***\t\n" ANSI_DEFAULT);

    get_data_for_prompt();
    prompt();
}

void get_input() {
    size_t size = 10;
    char *input;
    input = (char *)malloc(size);

    if (getline(&input, &size, stdin) < 0) {
        printf("An ERROR encounterd while reading the input");
    } else {
        printf("%s", input);
    }
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
