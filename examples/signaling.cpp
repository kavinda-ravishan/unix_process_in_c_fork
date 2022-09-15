#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <vector>

int main()
{

    int pid = fork();
    if(pid == -1)
    {
        printf("Process not created.\n");
        return -1;
    }

    if(pid != 0)
    {
        kill(pid, SIGSTOP);
    }

    if(pid == 0) // C
    {
        while (true)
        {
            printf("From child process.\n");
            sleep(1);
        }
    }
    else // P
    {
        int t;
        do
        {
            printf("Time in seconds for execution : ");
            scanf("%d", &t);

            if(t <= 0) continue;

            kill(pid, SIGCONT);
            sleep(t);
            kill(pid, SIGSTOP);

        } while (t != 0);
        

        kill(pid, SIGKILL);
        wait(NULL);
    }

    return 0;
}