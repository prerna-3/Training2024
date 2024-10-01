#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // Ignore SIGINT
    signal(SIGINT, SIG_IGN);

    printf("Running... (Press Ctrl+C; I won't stop!)\n");
    
    // Infinite loop to keep the program running
    while (1) {
        sleep(1);
    }

    return 0;
}

