#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT! But I'm still running...\n");
}

int main() {
    // Register signal handler
    signal(SIGINT, handle_sigint);

    printf("Running... (Press Ctrl+C to trigger SIGINT)\n");
    
    // Infinite loop to keep the program running
    while (1) {
        sleep(1);
    }

    return 0;
}

