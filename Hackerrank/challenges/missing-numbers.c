#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

int main()
{
    int32_t n, m;
    int32_t freq[200];

    memset ( freq, 0, 200 * sizeof ( int32_t ) );

    scanf ( "%d", &n );

    int x0;
    scanf ( "%d", &x0 );
    n--;
    freq[100] = 1;

    while ( n-- > 0 )
    {
        int x;
        scanf ( "%d", &x );
        freq[x - x0 + 100]++;
    }

    scanf ( "%d", &m );

    while ( m-- > 0 )
    {
        int x;
        scanf ( "%d", &x );
        freq[x - x0 + 100]--;
    }

    for ( int i = 0; i < 200; i++ )
    {
        if ( freq[i] != 0 )
        {
            printf ( "%d ", i - 100 + x0 );
        }
    }


    // printf ( "\n" );

    return 0;
}
