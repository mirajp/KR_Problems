#include <stdio.h>

#define MAXWORDLENGTH 25
#define BARWIDTH 3


int lengthCounts[MAXWORDLENGTH];

int main() {
    int c, i, j, curLength = 0, maxFreq = 0;

    while ((c = getchar()) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            curLength++;
        else {
            if (curLength) {
                lengthCounts[curLength-1]++;
                curLength = 0;
            }
        }

    }

    for (i = 0; i < MAXWORDLENGTH; i++) {
        if (lengthCounts[i] > maxFreq)
            maxFreq = lengthCounts[i];
        //printf("Number of words of length %d: %d\n", i+1, lengthCounts[i]);
    }
    
    //printf("Highest freq: %d\n", maxFreq);
    int charCount = 0;
    printf("\t\t\t\tHistogram of word length frequencies\n");
    for (j = maxFreq; j>= 1; j--) {
        printf("%d\t\t", j);
        for (i = 0; i < MAXWORDLENGTH; i++) {
            if (lengthCounts[i] >= j) {
                for (charCount = 0; charCount < BARWIDTH; charCount++)
                    printf("\u2588");
            }
            else {
                for (charCount = 0; charCount < BARWIDTH; charCount++)
                    printf(" ");
            }
        }
        printf("\n");
    }
    int length = 1;
    
    printf("Lengths:\t");
    for (i = 0; i < MAXWORDLENGTH; i++) {
        if (i+1 < 10)
            printf(" %d ", i+1);
        else
            printf(" %d", i+1);
    }
    printf("\n");
    return 0;
}
