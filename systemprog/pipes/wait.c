#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int pipe_fd[2]; // Pipe file descriptors

void signal_handler(int signum) {
    // Empty handler, just wakes up the parent
}

int main() {
    pid_t pid;
    char message[100];
    char buffer[100];

    // Create the pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(pipe_fd[0]); // Close read end

        // Set up the signal handler
        signal(SIGUSR1, signal_handler);

        for (int i = 0; i < 5; i++) {
            // Prepare the message
            snprintf(message, sizeof(message), "Chunk %d from parent", i + 1);
            write(pipe_fd[1], message, strlen(message) + 1);
            printf("Parent sent: %s\n", message);
            kill(pid, SIGUSR1); // Send signal to child
            pause(); // Wait for signal from child
        }

        close(pipe_fd[1]); // Close write end
    } else { // Child process
        close(pipe_fd[1]); // Close write end

        while (1) {
            // Read the message from the parent
            if (read(pipe_fd[0], buffer, sizeof(buffer)) > 0) {
                printf("Child received: %s\n", buffer);
                kill(getppid(), SIGUSR1); // Notify parent to send next chunk
            } else {
                break; // Exit if read fails (pipe closed)
            }
        }

        close(pipe_fd[0]); // Close read end
    }

    return 0;
}
        
