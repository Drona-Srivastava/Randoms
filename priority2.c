#include <stdio.h>
#include <limits.h>
struct process {
    int pid;        
    int burst;     
    int priority;  
    int wait;      
    int turnaround; 
    int remaining;  
};

int highestPriorityProcess(struct process proc[], int n, int time) {
    int idx = -1;
    int highestPriority = INT_MAX; 

    for (int i = 0; i < n; i++) {
        if (proc[i].remaining > 0 && proc[i].priority < highestPriority) {
            highestPriority = proc[i].priority;
            idx = i;
        }
    }
    return idx;
}

void calc(struct process proc[], int n) {
    int completed = 0;
    int time = 0; 

    while (completed < n) {
        int idx = highestPriorityProcess(proc, n, time);

        if (idx != -1) {
            proc[idx].remaining--;  
            time++; 

            if (proc[idx].remaining == 0) {
                proc[idx].turnaround = time;  
                proc[idx].wait = proc[idx].turnaround - proc[idx].burst; 
                completed++; 
            }
        } else {
            time++;
        }
    }
}

void print(struct process proc[], int n) {
    float avgWait = 0, avgTurnaround = 0;

    printf("\nPID\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", proc[i].pid, proc[i].burst, proc[i].priority, proc[i].wait, proc[i].turnaround);
        avgWait += proc[i].wait;
        avgTurnaround += proc[i].turnaround;
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWait / n);
    printf("Average Turnaround Time: %.2f\n", avgTurnaround / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of P%d: ", i + 1);
        scanf("%d", &proc[i].burst);
        printf("Enter the priority of P%d: ", i + 1);
        scanf("%d", &proc[i].priority);
        proc[i].pid = i + 1;  
        proc[i].remaining = proc[i].burst;  
    }

    calc(proc, n);
    print(proc, n);

    return 0;
}
