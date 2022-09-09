#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>

std::vector<int> vec;

int main(int argc, char* argv[])
{
    int id = fork();
    if(id != 0)
    {
        // main process
        vec.push_back(123);
    }
    else
    {
        vec.push_back(456);
    }

    int status;
    if(id != 0)
    {
        // main process
        wait(&status);
    }

    if(id != 0)
    {
        // main process
        for(int i : vec)
        {
            printf("pid : %d, val : %d\n", id, i);
            fflush(stdout);
        }
    }

    return 0;
}