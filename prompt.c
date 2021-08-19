
#include "prompt.h"

#include "shell.h"
#include "utils.h"

void get_data_for_prompt() {
    user_name = getlogin();
    host_name = (char *)malloc(sizeof(char) * (HOST_NAME_MAX + 1));
    gethostname(host_name, (HOST_NAME_MAX + 1));
}

void prompt() {
    char *path;
    path = "~";
    char* abs_path = getcwd(NULL, 0);
    printf("\n<" ANSI_GREEN_BOLD "%s@%s" ANSI_DEFAULT ":" ANSI_CYAN "%s" ANSI_DEFAULT "> ", user_name, host_name, abs_path);
    fflush(stdout);
}
