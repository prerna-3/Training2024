#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int pipe_fd[2];
    pid_t pid;
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

        // Open the input file
        FILE *file = fopen("input.txt", "r");
        if (!file) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        while (fgets(buffer, sizeof(buffer), file)) {
            write(pipe_fd[1], buffer, strlen(buffer) + 1);
        }

        fclose(file);
        close(pipe_fd[1]); // Close write end
    } else { // Child process
        close(pipe_fd[1]); // Close write end

        // Open the output file
        FILE *file = fopen("output.txt", "w");
        if (!file) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        while (read(pipe_fd[0], buffer, sizeof(buffer)) > 0) {
            fprintf(file, "%s", buffer);
        }

        fclose(file);
        close(pipe_fd[0]); // Close read end
    }

    return 0;
}

