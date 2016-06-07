#include <stdio.h>
#include <ctype.h>
#include <math.h>

// atof: convert string s to double, based on function provided in K&R, extended
// to handle scientific notation, ex. "123.45E2" | "123.45e+2" = 12345
double atof(char s[]) {
    double val, power, esign;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) {
        ; // skip over white space
    }

    sign = (s[i] == '-') ? -1 : 1;

    // skip over the sign designating character if provided
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10*val + (s[i]-'0');

    // capture the decimal value, if present
    if (s[i] == '.') {
        i++;
        for (power = 1.0; isdigit(s[i]); i++) {
            val = 10*val + (s[i]-'0');
            power *= 10;
        }
    }

    // capture the exponent part, if present
    if (s[i] == 'e' || s[i] == 'E') {
        i++;

        // if exponent is positive, then decrease the magnitude of the
        // power that will be used to divide the value
        // else if negative, increase power 10-fold for each digit as was done
        // during the decimal value capture
        esign = (s[i] == '-') ? 10 : 0.10;

        if (s[i] == '+' || s[i] == '-')
            i++;

        for ( ; isdigit(s[i]); i++) {
            val = 10*val + (s[i] - '0');
            power *= esign;
        }
    }

    return (sign*val/power);
}

int main() {
    char testval[] = "123.45e2";
    printf("Value of %s = %f\n", testval, atof(testval));
}
