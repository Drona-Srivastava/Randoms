#include <stdio.h>

struct process {
    int pid;
    int burst;
    int wait;
    int turn;
    int remaining;
    int completion;
};

void calc(struct process proc[], int n, int q) {
    int time = 0;
    int completed = 0;

    // Run the processes in round robin fashion
    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining > 0) {
                if (proc[i].remaining > q) {
                    time += q;
                    proc[i].remaining -= q;
                } else {
                    time += proc[i].remaining;
                    proc[i].wait = time - proc[i].burst;
                    proc[i].remaining = 0;
                    proc[i].completion = time;
                    completed++;
                }
            }
        }
    }

    // Calculate turn-around time (turn = burst + wait)
    for (int i = 0; i < n; i++) {
        proc[i].turn = proc[i].burst + proc[i].wait;
    }
}

void table(struct process proc[], int n) {
    int totalwait = 0, totalturn = 0;

    // Calculate total wait and total turn-around times
    for (int i = 0; i < n; i++) {
        totalwait += proc[i].wait;
        totalturn += proc[i].turn;
    }

    // Calculate average wait and turn-around times
    int avgwait = totalwait / n;
    int avgturn = totalturn / n;

    // Print average wait and turn-around times
    printf("Average waiting time: %d\n", avgwait);
    printf("Average turn-around time: %d\n", avgturn);

    // Print process table
    printf("PID\tBurst\tCompletion\tWait\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst, proc[i].completion, proc[i].wait, proc[i].turn);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst);
        proc[i].remaining = proc[i].burst;  // Initialize remaining time to burst time
    }

    int q;
    printf("Enter the quantum time: ");
    scanf("%d", &q);

    // Calculate scheduling details
    calc(proc, n, q);

    // Display process table with results
    table(proc, n);

    return 0;
}
