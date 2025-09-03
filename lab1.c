#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Check if the user provided exactly one argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <non-negative integer>\n", argv[0]);
        return 1;
    }

    // Convert argument to integer
    int n = atoi(argv[1]);
    if (n < 0) {
        fprintf(stderr, "ERROR: Please enter a non-negative integer.\n");
        return 1;
    }

    // Fork a new process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
        // Child process: print Fibonacci sequence
        printf("Child process PID: %d\n", getpid());
        int a = 0, b = 1, c;

        for (int i = 0; i < n; i++) {
            printf("fib%d = %d\n", i, a);
            c = a + b;
            a = b;
            b = c;
        }
        printf("Child process terminated.\n");
    } 
    else {
        // Parent process: wait for child to finish
        printf("Parent process PID: %d\n", getpid());
        printf("Parent waiting for child to complete...\n");
        waitpid(pid, NULL, 0);
        printf("Parent process terminated.\n");
    }

    return 0;
}

