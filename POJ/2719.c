/*
 * POJ2719
 * Sep 4, 2016
 */

#include <stdio.h>

int main()  
{  
    long input;
    while(~scanf("%ld", &input) && input) {
        long temp = input;
        long i = 1, m = 0;
        while(temp) {
            long t = temp % 10;
            temp /= 10;
            if(t > 4) t --;
            m += t * i;
            i *= 9;
        }

        printf("%ld: %ld\n", input, m );
    }

    return 0;
}

