#include <stdio.h>

struct process{
    int pid;
    int arrival;
    int burst;
    int completion;
    int wait;
    int turnaround;
    int is_done;
};

void calc(struct process proc[],int n){
    int time=0, completed=0,min_index;

    while(completed!=n){
        int min_time = 100000000;
        min_index = -1;

        for(int i=0;i<n;i++){
            if(proc[i].arrival <= time && !proc[i].is_done && proc[i].burst <= min_time){
                min_index = i;
                min_time = proc[i].burst;
            }
        }

        if(min_index == -1){
            time++;
            continue;
        }

        time = time + proc[min_index].burst;
        proc[min_index].completion = time; //end time
        proc[min_index].wait = time - proc[min_index].burst - proc[min_index].arrival; //arrival
        proc[min_index].turnaround = proc[min_index].wait + proc[min_index].burst; //turnaround
        proc[min_index].is_done = 1;
        completed++;
    }
}

void print(struct process proc[],int n){
    int totalwait=0,totalturn=0,avgwait,avgturn;
    for(int i=0;i<n;i++){
        totalwait = totalwait + proc[i].wait;
        totalturn = totalturn + proc[i].turnaround;
    }

    avgwait = totalwait/n;
    avgturn = totalturn/n;
    
    printf("Average Waiting time is: %d\n",avgwait);
    printf("Average turnaround time is: %d\n",avgturn);

    printf("PID\t\tArrival\t\tBurst\t\tCompletion\tWait\t\tTurnaround\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].arrival,proc[i].burst,proc[i].completion,proc[i].wait,proc[i].turnaround);
    }   
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    struct process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", proc[i].pid);
        scanf("%d", &proc[i].arrival);
        printf("Enter burst time for process %d: ", proc[i].pid);
        scanf("%d", &proc[i].burst);
        proc[i].is_done = 0;
        printf("\n");
    }

    calc(proc, n);
    print(proc, n);

    return 0;
}