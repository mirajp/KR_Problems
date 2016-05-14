#include <stdio.h>

#define MAXWORDLENGTH 25

int lengthCounts[MAXWORDLENGTH+1];

int main() {
    int c, i, curLength = 0;

    while ((c = getchar()) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            curLength++;
        else {
            lengthCounts[curLength]++;
            curLength = 0;
        }

    }

    for (i = 1; i <= MAXWORDLENGTH; i++) {
        printf("Number of words of length %d: %d\n", i, lengthCounts[i]);
    }

    return 0;
}
