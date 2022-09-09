#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int id = fork();

    // if id = 0, it is from chilled process. if it is not zero, from main process
    //printf("Process id : %d\n", id);

    if(id == 0)
    {
        printf("From chilled process.\n");
    }
    else
    {
        printf("From main process.\n");
    }

    return 0;
}