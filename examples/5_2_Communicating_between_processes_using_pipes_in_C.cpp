#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <vector>

int main(int argc, char* argv[])
{
    int fd_vec[2];
    pipe(fd_vec);

    int fd_vec_size[2];
    pipe(fd_vec_size);
    
    int id = fork();

    if(id == 0)
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        const int size = vec.size();

        close(fd_vec_size[0]);
        write(fd_vec_size[1], &size, sizeof(int));
        close(fd_vec_size[1]);

        close(fd_vec[0]); // close read end
        write(fd_vec[1], &*vec.begin(), vec.size()*sizeof(int));
        close(fd_vec[1]); // close write end
    }
    else
    {
        wait(NULL);
        int size = 0;

        close(fd_vec_size[1]);
        read(fd_vec_size[0], &size, sizeof(int));
        close(fd_vec_size[0]);
        
        printf("Vec size : %d\n", size);
        std::vector<int> vec(size);

        close(fd_vec[1]); // close write end
        read(fd_vec[0], &*vec.begin(), sizeof(int)*3); 
        close(fd_vec[0]); // close read end

        for(auto i : vec)
        {
            printf("%d\n", i);
        }
    }


    return 0;
}