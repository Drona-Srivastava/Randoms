#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    printf("SUPP");
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i=0, j=(num-1); i<num ,j>0; i++,j--){
        arr[i] = arr[j];
    }
    for(int i=0; i<num ;i++){
        printf("%d",*(arr+i));
    }
}
