#include "utils.h"

#include "prompt.h"

void initialize_everything() {
    printf(ANSI_CLEAR);
    printf(ANSI_YELLOW_BOLD "\n\t***\tWelcome to SeaShell\t***\t\n" ANSI_DEFAULT);

    get_data_for_prompt();
    prompt();
}

void get_input() {
    int bytes_read;
    size_t size = 10;
    char *input;
    input = (char *)malloc(size);
    bytes_read = getline(&input, &size, stdin);

    if (bytes_read < 0) {
        printf("An ERROR encounterd while reading the input");
    } else {
        printf("%s", input);
    }
}

bool handle_command() {
    get_input();
    prompt();
    return false;
}
