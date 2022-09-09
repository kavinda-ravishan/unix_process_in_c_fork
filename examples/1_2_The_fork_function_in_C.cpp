#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    fork();
    //   |_
    //   | |
    fork();
    //    |______
    //    |__    |__
    //    |  |   |  |
    fork();
    //    |________
    //    |____    |___
    //    |_   |_  |_  |_
    //    | |  | | | | | |
    //    1 2  3 4 5 6 7 8
    // app will print 8 times, 2 to the power 3(num of forks) or 2 x 2 x 2.
    printf("app\n");

    return 0;
}