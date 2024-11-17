#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

struct dirent* dptr;

int main(int argc, char* argv[]){
    DIR* dirp;
    char buff[1000];

    printf("Enter the directory: ");
    scanf("%[^\n]s",buff);

    if((dirp = opendir(buff)) == NULL){
        printf("No such directory exists.\n");
        exit(1);
    }
    while(dptr = readdir(dirp)){
        printf("%s\n",dptr->d_name);
    }
    closedir(dirp);
}