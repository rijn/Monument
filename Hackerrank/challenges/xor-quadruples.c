#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <inttypes.h>

int main()
{
    int A;
    int B;
    int C;
    int D;
    scanf ( "%d %d %d %d", &A, &B, &C, &D );

    int e;

    if ( A > B )
    {
        e = A;
        A = B;
        B = e;
    }

    if ( A > C )
    {
        e = A;
        A = C;
        C = e;
    }

    if ( A > D )
    {
        e = A;
        A = D;
        D = e;
    }

    if ( B > C )
    {
        e = B;
        B = C;
        C = e;
    }

    if ( B > D )
    {
        e = B;
        B = D;
        D = e;
    }

    if ( C > D )
    {
        e = C;
        C = D;
        D = e;
    }

    int64_t count = 0;

    for ( int i = 1; i <= A; i++ )
    {
        for ( int j = i; j <= B; j++ )
        {
            count += ( ( D - j + 1 ) + ( D - C + 1 ) ) * ( ( D - j + 1 ) - ( D - C + 1 ) + 1 ) / 2;
        }
    }

    // count -= ( ( C ) + ( C - A + 1 ) ) * ( ( C ) - ( C - A + 1 ) + 1 ) / 2;

    int xor_value[6000];

    for ( int i = 0; i < 6000; i++ )
    {
        xor_value[i] = 0;
    }

    for ( int i = 1; i <= C; i++ )
    {
        for ( int j = i; j <= D; j++ )
        {
            xor_value[i ^ j] ++;
        }
    }

    for ( int i = 1; i <= B; i++ )
    {
        for ( int j = 1; j <= A && j <= i; j++ )
        {
            count -= xor_value[i ^ j];
        }

        for ( int j = i; j <= D; j++ )
        {
            xor_value[i ^ j]--;
        }
    }

    // for ( int i = 1; i <= A; i++ )
    // {
    //     for ( int j = i; j <= B; j++ )
    //     {
    //         count += ( ( D - j + 1 ) + ( D - C + 1 ) ) * ( ( D - j + 1 ) - ( D - C + 1 ) + 1 ) / 2;
    //     }
    // }

    // count -= ( ( C ) + ( C - A + 1 ) ) * ( ( C ) - ( C - A + 1 ) + 1 ) / 2;

    // printf ( "count=%lld\n", count );

    // int xor_value[3001][3001];
    // int xor_count[6001], xor_count_2[6001];

    // for ( int i = 0; i < 6000; i++ )
    // {
    //     xor_count[i] = 0;
    //     xor_count_2[i] = 0;
    // }

    // for ( int i = 1; i <= C; i++ )
    // {
    //     for ( int j = i + 1; j <= D; j++ )
    //     {
    //         // xor_value[i][j] = i ^ j;
    //         xor_count[i ^ j] ++;
    //     }
    // }

    // for ( int i = 1; i <= A; i++ )
    // {
    //     for ( int j = i + 1; j <= B; j++ )
    //     {
    //         // xor_value[i][j] = i ^ j;
    //         xor_count_2[i ^ j] ++;
    //     }
    // }

    // // for ( int i = 1; i <= C; i++ )
    // // {
    // //     for ( int j = 1; j <= D; j++ )
    // //     {
    // //         printf ( "%d\t", xor_value[i][j] );
    // //     }

    // //     printf ( "\n" );
    // // }

    // // for ( int i = 1; i <= D; i++ )
    // // {
    // //     printf("%d\t", xor_count[i]);
    // // }

    // for ( int i = 0; i < 6000; i++ )
    // {
    //     if ( xor_count[i] > 1 && xor_count_2[i] > 1 )
    //     {
    //         count -= ( xor_count[i] - 1 ) * ( xor_count_2[i] - 1 ) / 2;
    //     }
    // }

    printf ( "count=%lld\n", count );

    return 0;
}
