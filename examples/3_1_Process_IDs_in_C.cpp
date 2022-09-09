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
        wait(&status);

        printf("Main ID                 : %d\n", id);
        printf("Main Process id         : %d\n", getpid());
        printf("Main Parent Process id  : %d\n\n", getppid());
    }
    else
    {
        printf("Child ID                : %d\n", id);
        printf("Child Process id        : %d\n", getpid());
        printf("Child Parent Process id : %d\n\n", getppid());
    }
    

    return 0;
}