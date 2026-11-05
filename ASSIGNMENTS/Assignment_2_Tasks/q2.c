#include <stdio.h>

#define N 4

/*
 * Q2: CPU Scheduling - Round Robin Simulation
 */
int main(int argc, char **argv)
{
    const char *name[N] = {"P1", "P2", "P3", "P4"};
    int arrival[N] = {0, 1, 2, 3};
    int burst[N] = {8, 4, 9, 5};
    int quantum = 3;
    if (argc > 1) { 
        quantum = 0; 
        for (const char *s = argv[1]; *s; s++) 
            quantum = quantum * 10 + (*s - '0'); 
    }

    int left[N], finish[N], queue[64], head = 0, tail = 0, added[N] = {0};
    for (int i = 0; i < N; i++) left[i] = burst[i];
    int time = 0, done = 0, switches = 0;
    queue[tail++] = 0;
    added[0] = 1;
    
    printf("--- Q2: Round Robin CPU Scheduling (Quantum = %d) ---\n", quantum);
    printf("Gantt:");
    while (done < N) {
        int p = queue[head++];
        int run = left[p] < quantum ? left[p] : quantum;
        printf(" %s(%d-%d)", name[p], time, time + run);
        time += run;
        left[p] -= run;
        switches++;
        for (int i = 0; i < N; i++)
            if (!added[i] && arrival[i] <= time) { queue[tail++] = i; added[i] = 1; }
        if (left[p] > 0) queue[tail++] = p;
        else { finish[p] = time; done++; }
    }
    double tw = 0, tt = 0;
    printf("\n\nProcess   TAT   WT\n");
    for (int i = 0; i < N; i++) {
        int tat = finish[i] - arrival[i], wt = tat - burst[i];
        tt += tat;
        tw += wt;
        printf("%-7s %4d %4d\n", name[i], tat, wt);
    }
    printf("\nAverage TAT = %.2f, Average WT = %.2f\n", tt / N, tw / N);
    printf("Time slices (dispatches) = %d, Context switches = %d\n", switches, switches - 1);
    return 0;
}