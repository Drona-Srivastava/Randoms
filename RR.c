#include <stdio.h>

struct Process {
    int id;             
    int burst_time;    
    int waiting_time;  
    int turn_around_time; 
    int remaining_time; 
};

void findWaitingTime(struct Process proc[], int n, int quantum) {
    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                done = 0;
                if (proc[i].remaining_time > quantum) {
                    t += quantum;
                    proc[i].remaining_time -= quantum;
                } 
                else {
                    t += proc[i].remaining_time;
                    proc[i].waiting_time = t - proc[i].burst_time;
                    proc[i].remaining_time = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
}

void findTurnAroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void findAverageTime(struct Process proc[], int n, int quantum) {
    int total_wt = 0, total_tat = 0;

    findWaitingTime(proc, n, quantum);

    findTurnAroundTime(proc, n);

    printf("Processes\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].waiting_time;
        total_tat += proc[i].turn_around_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, proc[i].waiting_time, proc[i].turn_around_time);
    }

    printf("Average Waiting Time = %.2f\n", (float)total_wt / (float)n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
    int n; 
    int quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n]; 

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst_time);
        proc[i].remaining_time = proc[i].burst_time;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    findAverageTime(proc, n, quantum);

    return 0;
}