#include <stdio.h>

struct process{
    int pid;
    int arrival;
    int burst;
    int wait;
    int turnaround;
};

void calc(struct process proc[], int n){
    for(int i=0;i<n;i++){ //All wait = 0
        proc[i].wait = 0;
    }

    //wait for each particular process
    for(int i=0;i<n;i++){
        if(i==0){
            proc[i].wait = 0;
        }
        else{
            for(int j=i-1; j>=0;j--){
                proc[i].wait = proc[i].wait + proc[j].burst;
            }
        }
    }

    //Turnaround
    for(int i=0;i<n;i++){
        proc[i].turnaround = proc[i].wait + proc[i].burst;
    }
}

void print(struct process proc[], int n){
    int totalwait = 0, totalturn=0;
    int avgwait,avgturn;

    for(int i=0;i<n;i++){
        totalwait = totalwait + proc[i].wait;
        totalturn = totalturn + proc[i].turnaround;
    }

    avgwait = totalwait/n;
    avgturn = totalturn/n;

    printf("Average wait time: %d\n",avgwait);
    printf("Average turnaround time: %d\n",avgturn);

    printf("PID\t\tArrival\t\tBurst\t\tWait\t\tTurnaround\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].arrival,proc[i].burst,proc[i].wait,proc[i].turnaround);
    }
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\n");
    struct process proc[n];

    for(int i=0;i<n;i++){
        printf("Enter the arrival time of process PID %d: ",i+1);
        scanf("%d",&proc[i].arrival);
        printf("Enter the burst time of process PID %d: ",i+1);
        scanf("%d",&proc[i].burst);
        printf("\n");
        proc[i].pid = i+1;
    }

    calc(proc,n);
    print(proc,n);
}