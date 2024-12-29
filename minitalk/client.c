#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void send_char(pid_t server_pid, char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if (c & (128 >> bit))
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        usleep(100);
        bit++;
    }
}

void send_message(pid_t server_pid, char *message)
{
    while (*message)
        send_char(server_pid, *message++);
    send_char(server_pid, '\0');
}
