#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// client.c
void    send_char(pid_t server_pid, char c);
void    send_message(pid_t server_pid, char *message);

// server.c
void    handle_signal(int signum, siginfo_t *info, void *context);

#endif
