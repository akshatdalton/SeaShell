#include "shell.h"

#include "utils.h"

int main() {
    initialize_everything();

    while (true) {
        if (handle_command()) {
            // If `quit` command is given we need to break here.
            break;
        }
    }

    return 0;
}
