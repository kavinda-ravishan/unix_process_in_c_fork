#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int id = fork();
    int status;
    if(id != 0)
    {
        printf("Main ID                 : %d\n", id);
        printf("Main Process id         : %d\n", getpid());
        printf("Main Parent Process id  : %d\n\n", getppid());
    }
    else
    {
        sleep(1); // wait until parent process die
        printf("Child ID                : %d\n", id);
        printf("Child Process id        : %d\n", getpid());
        printf("Child Parent Process id : %d\n\n", getppid());
        // When the parent process dies, the child process is assigned a new parant process id.
    }
    
    // Make sure all child processes have terminated before the parent process.
    // wait(NULL);

    return 0;
}