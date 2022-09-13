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
        vec.push_back(11);
        vec.push_back(22);
        vec.push_back(33);
        vec.push_back(44);

        const int size = vec.size();

        close(fd_vec_size[0]);
        write(fd_vec_size[1], &size, sizeof(int));
        close(fd_vec_size[1]);

        close(fd_vec[0]); // close read end
        write(fd_vec[1], vec.data(), vec.size()*sizeof(int));
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
        read(fd_vec[0], vec.data(), sizeof(int)*size); 
        close(fd_vec[0]); // close read end

        for(auto i : vec)
        {
            printf("%d\n", i);
        }
    }


    return 0;
}