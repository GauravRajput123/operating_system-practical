#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

int main() {
    int n, total_waiting_time = 0, total_turnaround_time = 0, current_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nGantt Chart:\n");

    while (1) {
        int shortest_job = -1;
        int min_remaining_time = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < min_remaining_time && processes[i].remaining_time > 0) {
                shortest_job = i;
                min_remaining_time = processes[i].remaining_time;
            }
        }

        if (shortest_job == -1)
            break;

        printf("P%d ", processes[shortest_job].id);
        processes[shortest_job].remaining_time--;

        if (processes[shortest_job].remaining_time == 0) {
            int turnaround_time = current_time - processes[shortest_job].arrival_time + 1;
            int waiting_time = turnaround_time - processes[shortest_job].burst_time - 2;
            total_turnaround_time += turnaround_time;
            total_waiting_time += waiting_time;
        }

        current_time++;
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\n\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}