
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigalrm(int sig) {
    printf("Alarm went off after 5 seconds!\n");
}

int main() {
    // Register signal handler
    signal(SIGALRM, handle_sigalrm);
    
    // Set an alarm for 5 seconds
    alarm(5);

    printf("Waiting for the alarm...\n");
    
    // Infinite loop to keep the program running
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}

