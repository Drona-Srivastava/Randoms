#include <stdio.h>

struct process
{
    int pid;
    int burst;
    int arrival;
    int priority;
    int remainging;
    int wait;
    int turn;
};

int sort(struct process proc[],int n,int time){
    int idx = -1;
    int highest = 1000000000000;
    
    for(int i=0;i<n;i++){
        
    }
}