#include "minitalk.h"

void handle_signal(int signum, siginfo_t *info, void *context)
{
    static int bit = 0;
    static char c = 0;
    static pid_t client_pid = 0;

    (void)context;
    if (client_pid == 0)
        client_pid = info->si_pid;
    if (signum == SIGUSR1)
        c |= (128 >> bit);
    bit++;
    if (bit == 8)
    {
        if (c == '\0')
        {
            write(1, "\n", 1);
            kill(client_pid, SIGUSR1); // Acknowledge receipt
            client_pid = 0;
        }
        else
            write(1, &c, 1);
        c = 0;
        bit = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("Server PID: %d\n", getpid());
    while (1)
        pause();

    return 0;
}
