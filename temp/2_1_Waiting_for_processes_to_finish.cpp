#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // example : print 1 to 10, 1 - 5 from main process, and 6 - 10 from child process
    int id = fork();
    int n;
    if(id == 0)
    {
        n = 1;
    }
    else
    {
        n = 6;
    }

    int status;
    if(id != 0)
    {
        // wait call from main process
        wait(&status); // Wait for a child process to die.
    }

    for(int i=n; i<n + 5; i++)
    {
        printf("%d ", i);
        fflush(stdout); // print the text right away
    }

    if(id != 0)
    {
        printf("\n");
    }

    return 0;
}