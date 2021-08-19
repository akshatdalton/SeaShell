
#include "prompt.h"

#include "shell.h"
#include "utils.h"

void get_data_for_prompt() {
    user_name = getlogin();

    host_name = (char *)malloc(sizeof(char) * (HOST_NAME_MAX + 1));
    gethostname(host_name, (HOST_NAME_MAX + 1));

    home_path = (char *)malloc(sizeof(char) * (MAX_STATIC_STR_LEN));
    home_path = get_home_path();
}

void prompt() {
    char *path;
    char *abs_path = getcwd(NULL, 0);
    path = get_relative_path(abs_path);

    printf("\n<" ANSI_GREEN_BOLD "%s@%s" ANSI_DEFAULT ":" ANSI_CYAN "%s" ANSI_DEFAULT "> ", user_name, host_name, path);
    fflush(stdout);

    free(path);
    free(abs_path);
}

char *get_home_path() {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    char *path = pw->pw_dir;
    return path;
}

char *get_relative_path(char *abs_path) {
    size_t home_path_len = strlen(home_path);
    char *relative_path = substr(abs_path, home_path_len, strlen(abs_path) - home_path_len);

    char *path;
    size_t relative_path_len = strlen(relative_path);
    path = (char *)malloc(sizeof(char) * (relative_path_len + 2));

    path[0] = '~';
    for (int ind = 0; ind < relative_path_len; ind++) {
        path[ind + 1] = relative_path[ind];
    }
    path[relative_path_len + 1] = '\0';

    return path;
}
