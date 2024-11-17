#include <stdio.h>

struct process{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int wait;
    int turn;
};

void calc(struct process proc[], int n){
    int time=0, completed=0,min_index,min_time;

    while(completed!=n){
        min_index = -1;
        min_time = 1000000;

        for(int i=0;i<n;i++){
            if(proc[i].arrival <= time && proc[i].remaining > 0 && proc[i].remaining < min_time){
                min_index = i;
            }
        }

        if(min_index==-1){
            time++;
            continue;
        }
        time++;
        proc[min_index].remaining--;

        if(proc[min_index].remaining == 0){
            proc[min_index].completion = time;
            proc[min_index].wait = time - proc[min_index].arrival - proc[min_index].burst;
            proc[min_index].turn = proc[min_index].wait + proc[min_index].burst;
            completed++;
        }
    }

    
}

void print(struct process proc[],int n){
    int totalwait,totalturn;
    int avgwait=0,avgturn=0;

    for(int i=0;i<n;i++){
        totalturn = totalturn + proc[i].turn;
        totalwait =  totalturn + proc[i].wait;
    }

    avgturn = totalturn/n;
    avgwait = totalwait/n;

    printf("Average Wait time is: %d\n",avgwait);
    printf("Average turnaround time is: %d\n",avgturn);

    printf("PID\t\tArrival\t\tBurst\t\tCompletion\t\tWait\t\tTurnaround\n");

    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].arrival,proc[i].burst,proc[i].completion,proc[i].wait,proc[i].turn);
    }
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\n");
    struct process proc[n];

    for(int i=0;i<n;i++){
        printf("Enter the arrival for process %d: ",i+1);
        scanf("%d",&proc[i].arrival);
        printf("Enter the burst for process %d: ",i+1);
        scanf("%d",&proc[i].burst);
        proc[i].pid = i+1;
        proc[i].remaining = proc[i].burst;
        printf("\n");
    }

    calc(proc,n);
    print(proc,n);
}