#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function for SIGINT
void sigintHandler(int signum) {
    printf("SIGINT signal caught!\n");
    exit(signum); // Terminate gracefully
}

int main() {
    // Registering the signal handler for SIGINT
    if (signal(SIGINT, sigintHandler) == SIG_ERR) {
        printf("Failed to register signal handler for SIGINT\n");
        return 1;
    }

    printf("Press Ctrl+C to generate a SIGINT signal...\n");

    // Keeping the program running to catch the signal
    while (1) {
        // The program will stay in this loop until a SIGINT signal is received
    }

    return 0;
}
