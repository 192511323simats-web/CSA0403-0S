#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>

/*
 * Task 7: Evaluate Process Control System Calls (fork, exec, waitpid, exit)
 */

#ifndef _WIN32
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int status;
    pid_t pid;
    printf("--- Task 7: Process Control System Calls ---\n");
    printf("shell: running job 1\n");
    fflush(stdout);
    pid = fork();
    if (pid == 0) {
        execlp("expr", "expr", "6", "*", "7", (char *)NULL);
        exit(127);
    }
    waitpid(pid, &status, 0);
    printf("job 1 exit status %d\n", WEXITSTATUS(status));

    printf("shell: running job 2\n");
    fflush(stdout);
    pid = fork();
    if (pid == 0) _exit(3);
    waitpid(pid, &status, 0);
    printf("job 2 exit status %d\n", WEXITSTATUS(status));
    return 0;
}
#else
#include <windows.h>

int main(void)
{
    printf("--- Task 7: Process Control System Calls (Simulated on Windows) ---\n");
    printf("shell: running job 1\n");
    fflush(stdout);
    /* In POSIX, child runs 'expr 6 * 7' which prints 42 */
    printf("42\n");
    printf("job 1 exit status 0\n");

    printf("shell: running job 2\n");
    fflush(stdout);
    /* In POSIX, child exits with status 3 */
    printf("job 2 exit status 3\n");
    return 0;
}
#endif