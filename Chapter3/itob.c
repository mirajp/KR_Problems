#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 32

void itoa(int n, char s[]);
void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void) {
    char s[MAXLEN];
    int i, n[] = {INT_MIN, 826, -2093}, base[] = {16, 16, 1};

    for (i = 0; i < sizeof(n)/sizeof(int); i++) {
        //itoa(n[i], s);
        itob(n[i], s, base[i]);
        printf("%d is converted to %s in base %d.\n", n[i], s, base[i]);
    }

    return 0;
}

// base 10 conversion, based on KR's itoa function
void itoa(int n, char s[]) {
    int i, sign, remainder;

    // Record the sign by just copying the number as K&R does
    sign = n;
    i = 0;
    do {
        // To account for the overflow of trying to turn INT_MIN positive (n = -n) and computing remainder with n % 10, get the remainder and make that positve
        remainder = n % 10;
        if (sign < 0)
            s[i++] = -remainder + '0';
        else
            s[i++] = remainder + '0';

    } while (n /= 10);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void itob(int n, char s[], int b) {

    int i, sign, remainder;
    char bases[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (b > strlen(bases) || b < 2) {
        fprintf(stderr, "Error: Base must be between 2 and %d\n", strlen(bases));
        s[0] = 'E';
        s[1] = 'R';
        s[2] = 'R';
        s[3] = '\0';
        return;
    }

    // Record the sign by just copying the number as K&R does
    sign = n;
    i = 0;
    do {
        // To account for the overflow of trying to turn INT_MIN positive (n = -n) and computing remainder with n % 10, get the remainder and make that positve
        remainder = n % b;
        if (sign < 0)
            s[i++] = bases[-remainder];
        else
            s[i++] = bases[remainder];

    } while (n /= b);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);

}

void reverse(char s[]) {
    int i, tmp;

    for (i = 0; i < strlen(s)/2; i++) {
        tmp = s[i];
        s[i] = s[strlen(s)-i-1];
        s[strlen(s)-i-1] = tmp;
    }
}
