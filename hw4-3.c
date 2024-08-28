#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    for(int i = 0; i < 2; i++)
    {
        int rc = fork();
        if (rc < 0) 
        {
            // fork failed; exit
            fprintf(stderr, "fork failed\n");
            exit(1);
        } 
        else if (rc == 0) 
        {
            // child (new process)
            printf("hello, I am child (pid:%d)\n", (int) getpid());
	        sleep(1);
        } 
        else 
        {
            // parent goes down this path (original process)
            int wc = waitpid(rc, *NULL, 0);
            printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
	        rc, wc, (int) getpid());
        }
    }
    return 0;
}
