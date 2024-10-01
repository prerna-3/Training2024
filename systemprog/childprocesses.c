#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_children>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            return 1;
        } else if (pid == 0) {
            // Child process
            printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
            return 0; // Child terminates here
        }
    }

    // Parent process
    for (int i = 0; i < n; i++) {
        wait(NULL); // Wait for all child processes
    }

    printf("All children have terminated.\n");
    return 0;
}

