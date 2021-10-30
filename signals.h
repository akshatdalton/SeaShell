#ifndef __SIGNALS_H
#define __SIGNALS_H

#include <signal.h>

void initialize_signals();
void signal_handler(int signal_number);

#endif
