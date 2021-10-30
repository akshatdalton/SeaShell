#ifndef __PROMPT_H
#define __PROMPT_H

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

char* user_name;
char* host_name;
char* home_path;

void initialize_everything();
void get_data_for_prompt();
void prompt();
char* get_home_path();
char* get_relative_path(char* abs_path);

#endif
