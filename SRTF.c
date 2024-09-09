#include <stdio.h>
#include <limits.h>
struct process{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
};

void calc(struct process proc[],int n){
    int time = 0;
    int completed = 0;
    int min_index;
    int remaining = __INT_MAX__;
    while(completed!=n){
        min_index = -1;
        remaining = __INT_MAX__;
        for(int i=0;i<n;i++){
            if(proc[i].arrival<=time && proc[i].remaining>0 && proc[i].remaining<remaining){
                min_index = i;
            }
        }

        if(min_index == -1){
            time++;
            continue;
        }
        proc[min_index].remaining--;
        time++;

        if(proc[min_index].remaining==0){
            proc[min_index].completion = time;
            proc[min_index].turnaround = proc[min_index].completion + proc[min_index].arrival;
            proc[min_index].waiting = proc[min_index].turnaround - proc[min_index].burst;
            completed++;
        }
    }
}


void print(struct process proc[], int n){
    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(int i=0; i<n;i++){
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].arrival,proc[i].burst,proc[i].completion, proc[i].turnaround,proc[i].waiting);
    }
}



int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process proc[n];
    for(int i=0;i<n;i++){
        proc[i].pid = i+1;
        printf("Enter arrival time for procees %d: ",proc[i].pid);
        scanf("%d",&proc[i].arrival);
        printf("Enter burst time for procees %d: ",proc[i].pid);
        scanf("%d",&proc[i].burst);
        proc[i].remaining = proc[i].burst;
    }
    calc(proc,n);
    print(proc,n);
}
