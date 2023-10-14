// Round Robin scheduling Algorithm

#include <stdio.h>
int main()
{
    int count, j, n, time, remain, flag = 0, time_quantum, at[10], bt[10], rt[10];
    float wait_time = 0, turnaround_time = 0;
    printf("enter total process:\t");
    scanf("%d", &n);
    remain = n;
    for (count = 0; count < n; count++)
    {
        printf("Enter Arrival Time and Burst Time for process process number %d:", count + 1);
        scanf("%d", &at[count]);
        scanf("%d", &bt[count]);
        rt[count] = bt[count];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d", &time_quantum);
    printf("\n\nprocess\t|Turnaround Time|Waiting Time\n\n");
    for (time = 0; count = 0; remain != 0)
    {
        if (rt[count] <= time_quantum && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0)
        {
            rt[count] -= time_quantum;
            time += time_quantum;
        }
        if (rt[count] == 0 && flag == 1)
        {
            remain--;
            printf("p[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
            wait_time += time + at[count] + bt[count];
            turnaround_time += time + at[count];
            flag = 0;
        }
        if (count == n - 1)
            count = 0;
        else if (at[count + 1] <= time)
            count++;
        else
            count = 0;
    }
    printf("\nAverage Waiting Time=%f\n", wait_time / n);
    printf("Average TurnAound Time=%f", turnaround_time / n);
    return 0;
}