#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
/*
    P -- C2
    |
    C -- C3

    P  : id1 = x (C1), id2 = y (C2)
    C2 : id1 = x     , id2 = 0
    C  : id1 = 0     , id2 = z (C3)
    C3 : id1 = 0     , id2 = 0

    if last id zero (id), the process dose not have a child
*/
    int id1 = fork();
    int id2 = fork();

    if(id1 == 0)
    {
        if(id2 == 0)
        {
            printf("Process C3 -> id1 : %d, id2 : %d\n", id1, id2);
        }
        else
        {
            printf("Process C -> id1 : %d, id2 : %d\n", id1, id2);
        }
    }
    else
    {
        if(id2 == 0)
        {
            printf("Process C2 -> id1 : %d, id2 : %d\n", id1, id2);
        }
        else
        {
            printf("Process P -> id1 : %d, id2 : %d\n", id1, id2);
        }
    }

    // call wait ones, only wait for one child
    // Parent process have two children
    
    while (wait(NULL) != -1 || errno != ECHILD)
    {
        printf("Waited for a child to finish.\n");
    }
    

    return 0;
}