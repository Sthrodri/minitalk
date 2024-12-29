#include "minitalk.h"

void print_usage(char *program_name)
{
    fprintf(stderr, "Usage:\n");
    fprintf(stderr, "  To run as server: %s\n", program_name);
    fprintf(stderr, "  To run as client: %s <server_pid> <message>\n", program_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        // Act as server
        struct sigaction sa;

        sa.sa_flags = SA_SIGINFO;
        sa.sa_sigaction = handle_signal;
        sigemptyset(&sa.sa_mask);
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        printf("Server PID: %d\n", getpid());
        while (1)
            pause();
    }
    else if (argc == 3)
    {
        // Act as client
        pid_t server_pid;

        server_pid = (pid_t)atoi(argv[1]);
        if (server_pid <= 0)
        {
            fprintf(stderr, "Invalid server PID: %d\n", server_pid);
            exit(EXIT_FAILURE);
        }
        send_message(server_pid, argv[2]);
    }
    else
    {
        print_usage(argv[0]);
    }
    return 0;
}
