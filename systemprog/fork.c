

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Hello from child!\n");
    } else {
        // Parent process
        printf("Hello from parent!\n");
    }

    return 0;
}

