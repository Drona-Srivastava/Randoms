#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int sc = 0;
    char ch;
    FILE* fp;
    fp = fopen(argv[1],"r");
    if(fp == NULL){
        printf("Unable to open file.");
    }
    else{
        while(!feof(fp)){
            ch = fgetc(fp);
            if(ch == ' '){
                sc++;
            }
        }
        printf("No of spaces %d",sc);
        fclose(fp);
    }
}