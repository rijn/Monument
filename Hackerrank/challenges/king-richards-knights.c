#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

int main()
{
    int64_t N, S, L;
    int64_t * command, *initialArea, *searchArea;

    scanf ( "%lld", &N );
    scanf ( "%lld", &S );
    command = ( int64_t * ) malloc ( 3 * S * sizeof ( int64_t ) );
    initialArea = ( int64_t * ) malloc ( 3 * S * sizeof ( int64_t ) );
    searchArea = ( int64_t * ) malloc ( 4 * S * sizeof ( int64_t ) );

    for ( int64_t i = 0; i < S; i++ )
    {
        scanf ( "%lld%lld%lld", command + i * 3, command + i * 3 + 1, command + i * 3 + 2 );
        command[3 * i + 0]--;
        command[3 * i + 1]--;
    }

    initialArea[0] = command[0];
    initialArea[1] = command[1];
    initialArea[2] = command[2];
    searchArea[4 * 0 + 0] = initialArea[3 * 0 + 0];
    searchArea[4 * 0 + 1] = initialArea[3 * 0 + 0] + initialArea[3 * 0 + 2];
    searchArea[4 * 0 + 2] = initialArea[3 * 0 + 1];
    searchArea[4 * 0 + 3] = initialArea[3 * 0 + 1] + initialArea[3 * 0 + 2];

    for ( int64_t i = 1; i < S; i++ )
    {
        int64_t di = command[3 * i + 0] - command[3 * ( i - 1 ) + 0];
        int64_t dj = command[3 * i + 1] - command[3 * ( i - 1 ) + 1];

        initialArea[3 * i + 2] = command[3 * i + 2];

        switch ( i % 4 )
        {
            case 0:
                initialArea[3 * i + 0] = initialArea[3 * ( i - 1 ) + 0] + di;
                initialArea[3 * i + 1] = initialArea[3 * ( i - 1 ) + 1] + dj;
                break;

            case 1:
                initialArea[3 * i + 0] = initialArea[3 * ( i - 1 ) + 0] - dj + initialArea[3 * ( i - 1 ) + 2] - initialArea[3 * i + 2];
                initialArea[3 * i + 1] = initialArea[3 * ( i - 1 ) + 1] + di;
                break;

            case 2:
                initialArea[3 * i + 0] = initialArea[3 * ( i - 1 ) + 0] - di + initialArea[3 * ( i - 1 ) + 2] - initialArea[3 * i + 2];
                initialArea[3 * i + 1] = initialArea[3 * ( i - 1 ) + 1] - dj + initialArea[3 * ( i - 1 ) + 2] - initialArea[3 * i + 2];
                break;

            case 3:
                initialArea[3 * i + 0] = initialArea[3 * ( i - 1 ) + 0] + dj;
                initialArea[3 * i + 1] = initialArea[3 * ( i - 1 ) + 1] - di + initialArea[3 * ( i - 1 ) + 2] - initialArea[3 * i + 2];
                break;
        }

        searchArea[4 * i + 0] = initialArea[3 * i + 0];
        searchArea[4 * i + 1] = initialArea[3 * i + 0] + initialArea[3 * i + 2];
        searchArea[4 * i + 2] = initialArea[3 * i + 1];
        searchArea[4 * i + 3] = initialArea[3 * i + 1] + initialArea[3 * i + 2];

    }

    // for ( int64_t i = 0; i < S; i++ )
    // {
    // printf ( "(%d, %d, %d) (%d, %d, %d)\n", command[3 * i + 0], command[3 * i + 1], command[3 * i + 2], initialArea[3 * i + 0], initialArea[3 * i + 1], initialArea[3 * i + 2]);
    // }

    scanf ( "%lld", &L );

    while ( L-- > 0 )
    {
        int64_t w;
        scanf ( "%lld", &w );

        int64_t i = w / N, j = w % N;

        int64_t max = S - 1, min = -1, last = max / 2;

        while ( max > min )
        {
            if ( i >= searchArea[4 * last + 0] &&
                    i <= searchArea[4 * last + 1] &&
                    j >= searchArea[4 * last + 2] &&
                    j <= searchArea[4 * last + 3] )
            {
                min = last;
                int64_t temp = min + max;

                if ( temp % 2 == 1 )
                {
                    last = temp / 2 + 1;
                }
                else
                {
                    last = temp / 2;
                }
            }
            else
            {
                max = last - 1;
                last = ( min + max ) / 2;
            }
        }

        // printf("last = %lld\n", last);

        int64_t di = i - initialArea[3 * last + 0];
        int64_t dj = j - initialArea[3 * last + 1];

        if ( last >= 0 )
        {

            switch ( ( last + 1 ) % 4 )
            {
                case 0:
                    i = di + command[3 * last + 0];
                    j = dj + command[3 * last + 1];
                    break;

                case 1:
                    i = dj + command[3 * last + 0];
                    j = command[3 * last + 1] + command[3 * last + 2] - di;
                    break;

                case 2:
                    i = command[3 * last + 0] + command[3 * last + 2] - di;
                    j = command[3 * last + 1] + command[3 * last + 2] - dj;
                    break;

                case 3:
                    i = command[3 * last + 0] + command[3 * last + 2] - dj;
                    j = di + command[3 * last + 1];
                    break;
            }
        }

        printf ( "%lld %lld\n", i + 1, j + 1 );
    }

    return 0;
}
