#ifndef __PROMPT_H
#define __PROMPT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char* user_name;
char* host_name;

void get_data_for_prompt();
void prompt();

#endif
