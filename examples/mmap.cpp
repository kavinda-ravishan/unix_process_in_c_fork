#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <vector>

const int Vec_Size = 3;

int main()
{
    int* p = (int*) mmap(NULL, sizeof (int) * Vec_Size, PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    int id = fork();

    if(id == 0) // C
    {
        p[0] = 1;
        p[1] = 2;
        p[2] = 3;
    }
    else // P
    {
        wait(NULL);
        printf("%d\n", p[0]);
        printf("%d\n", p[1]);
        printf("%d\n", p[2]);
    }

    return 0;
}