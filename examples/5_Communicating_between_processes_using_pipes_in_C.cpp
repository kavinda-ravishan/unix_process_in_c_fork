#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    // file descriptors for two ends of the pipe 
    // fd[0] : read end
    // fd[1] : write end
    int fd[2];
    if(pipe(fd) == -1) // Returns 0 if successful, -1 if not.
    {
        printf("An error ocurred with opening the pipe\n");
        return 1;
    }

    int id = fork();
    if(id == -1)
    {
        printf("An error ocurred with fork\n");
        return 2;
    }

    if(id == 0)
    {
        close(fd[0]); // close the read end
        int x;
        printf("Enter a number : ");
        scanf("%d", &x);
        if(write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("An error ocurred with writing to the pipe\n");
            return 3;
        }
        close(fd[1]); // close the write end
    }
    else
    {
        close(fd[1]);
        int y;
        if(read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("An error ocurred with reading from the pipe\n");
            return 4;
        }
        close(fd[0]);
        printf("Value : %d\n", y);
    }

    return 0;
}