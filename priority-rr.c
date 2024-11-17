#include <stdio.h>

struct process {
    int pid;         
    int arrival;    
    int burst;       
    int priority;    
    int wait;         
    int turn;         
    int remaining;    
    int completion;   
};

void sort(struct process proc[], int n) {
    struct process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((proc[i].priority > proc[j].priority) || 
                (proc[i].priority == proc[j].priority && proc[i].arrival > proc[j].arrival)) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void calc(struct process proc[], int n, int q) {
    int time = 0;   // Current time
    int completed = 0;
    
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining > 0) {
                if (proc[i].remaining > q) {
                    time += q;
                    proc[i].remaining -= q;
                } else {
                    time += proc[i].remaining;
                    proc[i].remaining = 0;
                    proc[i].completion = time;
                    proc[i].turn = proc[i].completion - proc[i].arrival;
                    proc[i].wait = proc[i].turn - proc[i].burst;
                    completed++;
                }
            }
        }
    }
}


void print(struct process proc[], int n) {
    float avgWait = 0, avgTurnaround = 0;

    printf("\nPID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", proc[i].pid, proc[i].arrival, proc[i].burst, proc[i].priority, proc[i].wait, proc[i].turn);
        avgWait += proc[i].wait;
        avgTurnaround += proc[i].turn;
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
        printf("Enter the arrival time of P%d: ", i + 1);
        scanf("%d", &proc[i].arrival);
        proc[i].pid = i + 1; 
        proc[i].remaining = proc[i].burst;  
    }

    sort(proc, n);

    calc(proc, n,4);

    print(proc, n);
    return 0;
}
