#include <stdio.h>
#include <conio.h>

#define max 25
void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest;
    static int bf[max], ff[max];  

    printf("\tMemory Management Scheme - Worst Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("Enter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++) {
        highest = -1;
        for (j = 1; j <= nb; j++) {
            if (bf[j] == 0) { 
                temp = b[j] - f[i];
                if (temp >= 0) {
                    if (highest == -1 || temp > b[highest] - f[i]) {
                        highest = j;
                    }
                }
            }
        }

        if (highest != -1) { 
            ff[i] = highest;
            bf[highest] = 1;
            frag[i] = b[highest] - f[i]; 
        } else {
            ff[i] = -1; 
            frag[i] = -1;
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
    for (i = 1; i <= nf; i++) {
        if (ff[i] != -1) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated", i, f[i]);
        }
    }

    getch();
}
