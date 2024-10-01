#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        printf("Child process: My parent will terminate soon.\n");
        sleep(5);  // Simulate work
        printf("Child process: My parent is gone, I'm an orphan.\n");
    } else {
        // Parent process
        printf("Parent process is terminating.\n");
        _exit(0);  // Parent exits without waiting
    }
    
    return 0;
}

