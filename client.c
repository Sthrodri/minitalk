#include "minitalk.h"

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

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = (pid_t)atoi(argv[1]);
    if (server_pid <= 0)
    {
        fprintf(stderr, "Invalid server PID: %d\n", server_pid);
        return 1;
    }

    send_message(server_pid, argv[2]);
    return 0;
}
