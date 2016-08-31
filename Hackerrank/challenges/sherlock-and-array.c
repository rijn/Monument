#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int T;
    scanf ( "%d", &T );

    while ( T-- > 0 )
    {
        int32_t N, i;
        scanf ( "%d", &N );

        int * A = ( int * ) malloc ( N * sizeof ( int ) );

        int64_t sumA = 0;

        for (  i = 0; i < N; i++ )
        {
            scanf ( "%d", A + i );
            sumA += A[i];
        }

        int64_t sumB = 0;


        for ( i = 0; i < N; i++ )
        {
            sumA -= A[i];

            if ( sumA == sumB )
            {
                printf ( "YES\n" );
                break;
            }

            sumB += A[i];
        }

        if ( i == N )
        {
            printf ( "NO\n" );
        }

    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
