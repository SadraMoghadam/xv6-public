#include "types.h"
#include "stat.h"
#include "user.h"

void timeDelay(int delayIteration)
{
    for (int i = 0; i < delayIteration; i++)
        for (int j = 0; j < delayIteration; j++)
            i++;
}

int main(int argc, char *argv[])
{
    int pid, chpid;
    int wtime, rtime;
    pid = fork();
    if (pid > 0)
    {
        timeDelay(2000);
        chpid = waitx(&wtime, &rtime);
        printf(1, "----------------------------------------");
        printf(1, "\n\tchild pid: %d", chpid);
        printf(1, "\n\tParent wait time: %d", wtime);
        printf(1, "\n\tParent run time: %d", rtime);
        printf(1, "----------------------------------------");
    }
    if (pid == 0)
    {
        printf(1, "\nchild pid: %d", getpid());
    }
    else
    {
        printf(1, "\nnothing has been forked");
        exit();
    }
}


