#include <stdio.h>

int main()
{
    int nb, np, i, j;
    int block[20], process[20], allocation[20];

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter size of each block:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter size of each process:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &process[i]);

    for(i = 0; i < np; i++)
        allocation[i] = -1;

    for(i = 0; i < np; i++)
    {
        int best = -1;

        for(j = 0; j < nb; j++)
        {
            if(block[j] >= process[i])
            {
                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if(best != -1)
        {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");

    for(i = 0; i < np; i++)
    {
        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}