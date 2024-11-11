#include <stdio.h>
#include <stdbool.h>

#define MAX_Processes 5
#define MAX_Resources 3

void print_matrix(int matrix[MAX_Processes][MAX_Resources],int rows, int cols, char *name){
	printf("%s:\n",name);
	for(int i=0; i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool is_safe(int processes[],int available[], int max[][MAX_Resources],int allocation[][MAX_Resources],int need[][MAX_Resources]){
	bool finish[MAX_Processes] = {false};
	int safe_sequence[MAX_Processes];
	int work[MAX_Resources];
	
	for(int i=0;i<MAX_Resources;i++){
		work[i] = available[i];
	}
	
	int count=0;
	while(count<MAX_Processes){
		bool found=false;
		for(int p=0;p<MAX_Processes;p++){
			if(!finish[p]){
				int j;
				for(j=0;j<MAX_Resources;j++){
					if(need[p][j] > work[j]){
						break;
					}
				}
				if(j==MAX_Resources){
					for(int k=0;k<MAX_Resources;k++){
						work[k] += allocation[p][k];
					}
					safe_sequence[count++] = p;
					finish[p] = true;
					found = true;
				}
			}
		}
		if(!found){
			printf("The system is not in a safe state sequence.\n");
			return false;
		}
	}
	
	printf("The system is in a safe state sequence.\nSafe Sequence: ");
	for(int i=0;i<MAX_Processes;i++){
		printf("%d ",safe_sequence[i]);
	}
	printf("\n");
	return true;
}

int main(){
	int processes[MAX_Processes] = {0,1,2,3,4};
	int available[MAX_Resources] = {3,3,2};
	
	int max[MAX_Processes][MAX_Resources] = {
	{7,5,3},
	{3,2,2},
	{9,0,2},
	{2,2,2},
	{4,3,3}};
	
	int allocation[MAX_Processes][MAX_Resources] = {
	{0,1,0},
	{2,0,0},
	{3,0,2},
	{2,1,1},
	{0,0,2}};

	int need[MAX_Processes][MAX_Resources];
	for(int i=0;i<MAX_Processes;i++){
		for(int j=0;j<MAX_Resources;j++){
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	
	print_matrix(max,MAX_Processes,MAX_Resources,"Max Matrix");
	print_matrix(allocation,MAX_Processes,MAX_Resources,"Allocation Matrix");	
	print_matrix(need,MAX_Processes,MAX_Resources,"Need Matrix");
	
	is_safe(processes,available,max,allocation,need);
}