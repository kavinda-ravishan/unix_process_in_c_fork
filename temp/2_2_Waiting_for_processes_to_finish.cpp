#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int id = fork();
    if(id == 0)
    {
        printf("Child process id : %d\n", getpid());
    }
    
    // return -1 if there is no children, or return the process id of the process which terminated
    int res = wait(NULL);

    if(res == -1)
    {
        printf("No children to wait for.\n");
    }
    else
    {
        printf("Process with process id %d finished execution.\n", res);
    }

    return 0;
}