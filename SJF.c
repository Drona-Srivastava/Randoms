#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int is_completed;
};

void calculate_times(struct Process proc[], int n) {
    int time = 0, completed = 0, min_index;
    
    while (completed != n) {
        min_index = -1;
        int min_burst_time = 100000;

        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= time && !proc[i].is_completed && proc[i].burst_time < min_burst_time) {
                min_burst_time = proc[i].burst_time;
                min_index = i;
            }
        }

        if (min_index == -1) {
            time++;
            continue;
        }

        time += proc[min_index].burst_time;
        proc[min_index].completion_time = time;
        proc[min_index].turnaround_time = proc[min_index].completion_time - proc[min_index].arrival_time;
        proc[min_index].waiting_time = proc[min_index].turnaround_time - proc[min_index].burst_time;
        proc[min_index].is_completed = 1;
        completed++;
    }
}

void print_table(struct Process proc[], int n) {
    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].arrival_time,proc[i].burst_time,proc[i].completion_time,proc[i].turnaround_time, proc[i].waiting_time);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", proc[i].pid);
        scanf("%d", &proc[i].arrival_time);
        printf("Enter burst time for process %d: ", proc[i].pid);
        scanf("%d", &proc[i].burst_time);
        proc[i].is_completed = 0;
    }

    calculate_times(proc, n);
    print_table(proc, n);

    return 0;
}
