#include <stdio.h>

struct process {
    int pid;       
    int burst;    
    int priority; 
    int wait;     
    int turnaround; 
};

void sortByPriority(struct process proc[], int n) {
    struct process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void calc(struct process proc[], int n) {
    proc[0].wait = 0; 

    for (int i = 1; i < n; i++) {
        proc[i].wait = proc[i-1].wait + proc[i-1].burst;
    }

    for (int i = 0; i < n; i++) {
        proc[i].turnaround = proc[i].wait + proc[i].burst;
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
    }

    sortByPriority(proc, n);

    calc(proc, n);

    print(proc, n);

    return 0;
}
