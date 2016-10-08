/*
 * POJ 1631
 * 08/10/16
 */

#include <stdio.h>

int main() {
    int scenarios;
    scanf( "%d", &scenarios );

    while(scenarios --) {
        unsigned long ports;
        scanf( "%lu", &ports );

        long *lis = new long[ports + 1]();
        lis[0] = -1;

        long left  = 0,
             right = 0,
             len   = 0;

        for( unsigned i = 0; i < ports; i++ ) {
            long k;
            scanf( "%lu", &k );

            if( k > lis[len] ) {
                lis[++len] = k;
            } else {
                left = 0;
                right = len;
                while( left <= right ) {
                    long mid = ( left + right ) / 2;
                    if( lis[mid] <= k )
                        left = mid + 1;
                    else 
                        right = mid - 1;
                }
                lis[left] = k;
            }
        }

        delete[] lis;

        printf( "%lu\n", len );

    }

    return 0;
}
