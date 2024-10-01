#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signals(int sig) {
    if (sig == SIGINT) {
        printf("Caught SIGINT! I'm still running...\n");
    } else if (sig == SIGTERM) {
        printf("Caught SIGTERM! Terminating now...\n");
        _exit(0);
    }
}

int main() {
    // Register signal handler
    signal(SIGINT, handle_signals);
    signal(SIGTERM, handle_signals);

    printf("Running... (Press Ctrl+C to trigger SIGINT or send SIGTERM to terminate)\n");
    
    // Infinite loop to keep the program running
    while (1) {
        sleep(1);
    }

    return 0;
}

