#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        printf("Child process\n");
        _exit(0);  // Child exits
    } else {
        // Parent process does not call wait()
        printf("Parent process\n");
        sleep(10);  // Simulate doing some work
    }
    
    return 0;
}

