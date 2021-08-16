
#include "prompt.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "shell.h"

int main() {
    user_name = getlogin();
    host_name = (char*)malloc(sizeof(char) * (HOST_NAME_MAX + 1));
    gethostname(host_name, (HOST_NAME_MAX + 1));
    printf("<%s@%s:>", user_name, host_name);

    return 0;
}
