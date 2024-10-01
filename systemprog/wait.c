#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        printf("Child process\n");
        _exit(0);  // Child exits
    } else {
        // Parent process waits for child to terminate
        wait(NULL);  // Collects the child's exit status
        printf("Parent process cleaned up child\n");
    }
    
    return 0;
}

