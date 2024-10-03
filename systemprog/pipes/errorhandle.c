#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe_fd[2];
    pid_t pid;

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
        char message[] = "Hello from parent!";
        if (write(pipe_fd[1], message, strlen(message) + 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        close(pipe_fd[1]); // Close write end
    } else { // Child process
        close(pipe_fd[1]); // Close write end
        char buffer[100];
        if (read(pipe_fd[0], buffer, sizeof(buffer)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("Child received: %s\n", buffer);
        close(pipe_fd[0]); // Close read end
    }

    return 0;
}

