#include <stdio.h>
#include <string.h>

void *reverse(char *s) {
    int i;
    char tmp;
    for (i = 0; i < strlen(s)/2; i++) {
        tmp = s[strlen(s)-i-1];
        s[strlen(s)-i-1] = s[i];
        s[i] = tmp;
    }
    return;
}

int findNextSpace(char *s, int start) {
    for (; start < strlen(s); start++) {
        if (s[start] == ' ')
            return start;
    }
    return start;
}

void *reverseWords(char *s) {
    //To reverse the ordering of words in a string, reverse the order of
    //characters, then reverse the order of characters between spaces
    reverse(s);

    //The starting points are at the beginning of the string, and the first
    //character after the space. End points are the character before the space
    //and the end of the string.
    int i, start = 0, end = 0;
    char tmp;
    while ((end = findNextSpace(s, start)) <= strlen(s)) {
        for (i = start; i < start + (end-start)/2; i++) {
            tmp = s[end-i+start-1];
            s[end-i+start-1] = s[i];
            s[i] = tmp;
        }
        start = end + 1;
    }

    return;
}

int main() {
    char myStr[] = "The quick brown fox jumped over the lazy dog";

    printf("String before reversal: %s\n", myStr);

    reverseWords(myStr);

    printf("String after reversal: %s\n", myStr);

    return 0;
}
