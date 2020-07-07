#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid, chpid;
    int wtime, rtime;
    pid = fork();
    if (pid > 0)
    {
        delay(5);
        chpid = waitx(&wtime, &rtime);
        printf(1, "----------------------------------------")
        printf(1, "\n\tchild pid: %d", chpid);
        printf(1, "\n\tParent wait time: %d", wtime);
        printf(1, "\n\tParent run time: %d", rtime);
        printf(1, "----------------------------------------")
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
