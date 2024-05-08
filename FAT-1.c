#include <stdio.h>
int main(){
    float array[8];
    float temp=0.0;
    for (int i=0; i<8; i++){
        scanf("%f",&array[i]);
    }
    for(int i=0; i<8; i++){
        for(int j=i+1; j<8; j++){
            if(array[i]>array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    array[0]=0;
    array[7]=0;
    float sum=0.0;
    for (int i=0; i<8; i++){
        sum = sum + array[i];
    }
    printf("%0.1f",sum);
}