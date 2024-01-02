#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int signalCounter = 0; // Counter to track the number of signals caught

// Custom signal handler for SIGINT
void sigintHandler(int signum) {
    printf("Caught SIGINT signal: %d\n", signum);
    signalCounter++;

    if (signalCounter == 2) {
        // Resetting the signal handler to default behavior
        signal(SIGINT, SIG_DFL);
        printf("Signal handler reset to default behavior for SIGINT\n");
    }
}

int main() {
    // Registering the custom signal handler for SIGINT
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
