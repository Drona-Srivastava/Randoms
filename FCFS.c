#include <stdio.h>

struct process{
    int pid;
    int arrival;
    int burst;
    int wait;
    int turnaround;
};


void calc(struct process proc[], int n){
    //wait time
    for(int i=0; i<n; i++){
        proc[i].wait = 0;
    }
    
    for(int i=0; i<n; i++){
        if(i==0){
            proc[i].wait = 0;
        }
        else{
            for(int j=i-1; j>=0; j--){
                proc[i].wait = proc[i].wait + proc[j].burst;
            }
        }
    }

    //turnaround 
    for(int i=0; i<n; i++){
        proc[i].turnaround = proc[i].wait + proc[i].burst;
    }
}

void print(struct process proc[],int n){
    int totalwait = 0,totalturn = 0;
    int avgwait, avgturn;

    for(int i=0;i<n;i++){
        totalwait = totalwait + proc[i].wait;
    }
    avgwait = totalwait/n;

    for(int i=0; i<n; i++){
        totalturn = totalturn + proc[i].turnaround;
    }
    avgturn = totalturn/n;

    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for(int i=0;i<n;i++){   
        printf("%d\t%d\t%d\t%d\t%d\n",proc[i].pid,proc[i].arrival,proc[i].burst,proc[i].wait,proc[i].turnaround);
    }

    printf("\n");
    printf("Average Wait time is %d\n",avgwait);
    printf("Average Turnaround time is %d",avgturn);
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    
    struct process proc[n];

    for(int i=0; i<n; i++){
        proc[i].pid = i+1;
        printf("Enter arrival time for P%d: ",i+1);
        scanf("%d",&proc[i].arrival);
        printf("Enter burst time for P%d: ",i+1);
        scanf("%d",&proc[i].burst);
    }

    calc(proc,n);
    print(proc,n);
}