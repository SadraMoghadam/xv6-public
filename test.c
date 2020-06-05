#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
    int proc = fork();
    if (proc == 0)
    {
        proc = fork();
        if (proc == 0)
        {
            malloc(10 * sizeof(int));
            int max = 100;
            struct proc_info *processes = malloc(max * sizeof(struct proc_info));
            int info = getprocesses_info(max, processes);
            for (int i = 0; i < info; i++)
            {
                printf(1, "\npid : %d\n", processes[i].pid);
                printf(1, "memsize : %d \n\n", processes[i].memsize);
            }
        }
        else
        {
            malloc(30 * sizeof(int));
            wait();
        }
    }
    else
    {
        printf(1, "--------------------\n");
        wait();
    }
    wait();
    exit();
} 
