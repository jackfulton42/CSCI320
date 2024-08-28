#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int x = 100;
    printf("x = %d\n", x);
    int rc = fork();
    if(rc < 0)
    {
        printf("Fork failed.");
    }
    else if(rc == 0)
    {
        x += 100;
        printf("Child: x = %d\n", x);
    }
    else
    {
        x += 200;
        printf("Parent: x = %d\n", x);
    }

    //printf("x = %d\n", x);

    return 0;
}