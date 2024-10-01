#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 100

void child_sum(int *arr, int size, int index, int pipe_fd) {
    int sum = 0;
    for (int i = index; i < size; i += 2) {
        sum += arr[i];
    }
    write(pipe_fd, &sum, sizeof(sum));
    close(pipe_fd);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <size_of_array> <elements...>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n > MAX_SIZE || n < 1) {
        fprintf(stderr, "Size of array should be between 1 and %d\n", MAX_SIZE);
        return 1;
    }

    int arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 2]);
    }

    int pipe_fd[2];
    pipe(pipe_fd);
    for (int i = 0; i < 2; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            return 1;
        } else if (pid == 0) {
            // Child process
            close(pipe_fd[0]); // Close reading end
            child_sum(arr, n, i, pipe_fd[1]); // Alternate elements
        }
    }

    close(pipe_fd[1]); // Close writing end in parent

    int total_sum = 0;
    for (int i = 0; i < 2; i++) {
        int sum;
        read(pipe_fd[0], &sum, sizeof(sum));
        total_sum += sum;
    }

    wait(NULL);
    wait(NULL);
    close(pipe_fd[0]); // Close reading end after done

    printf("Total sum: %d\n", total_sum);
    return 0;
}

