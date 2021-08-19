#ifndef __UTILS_H
#define __UTILS_H

#define ANSI_RED "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"
#define ANSI_YELLOW "\033[0;33m"
#define ANSI_CYAN "\033[0;36m"
#define ANSI_RED_BOLD "\033[1;31m"
#define ANSI_GREEN_BOLD "\033[1;32m"
#define ANSI_YELLOW_BOLD "\033[1;33m"
#define ANSI_CYAN_BOLD "\033[1;36m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_CLEAR "\033[2J\033[1;1H"

#include <stdbool.h>

void initialize_everything();
bool handle_command();
void get_input();

#endif
