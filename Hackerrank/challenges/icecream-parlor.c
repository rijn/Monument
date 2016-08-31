#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>

int binarySearch ( int a[], int n, int key )
{
    int low = 0, high = n - 1;
    int mid;

    while ( low <= high )
    {
        mid = low + ( high - low ) / 2;

        if ( key < a[mid] )
        {
            high = mid - 1;
        }
        else if ( key > a[mid] )
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

void swap ( int * x, int * y )
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int choosePivot ( int i, int j )
{
    return ( ( i + j ) / 2 );
}

void quickSort ( int list[], int m, int n )
{
    int key, i, j, k;

    if ( m < n )
    {
        k = choosePivot ( m, n );
        swap ( &list[m], &list[k] );
        key = list[m];
        i = m + 1;
        j = n;

        while ( i <= j )
        {
            while ( ( i <= n ) && ( list[i] <= key ) )
            {
                i++;
            }

            while ( ( j >= m ) && ( list[j] > key ) )
            {
                j--;
            }

            if ( i < j )
            {
                swap ( &list[i], &list[j] );
            }
        }

        swap ( &list[m], &list[j] );

        quickSort ( list, m, j - 1 );
        quickSort ( list, j + 1, n );
    }
}

int main()
{
    int T;
    scanf ( "%d", &T );

    while ( T-- > 0 )
    {
        int M, N, i;
        scanf ( "%d%d", &M, &N );

        int * c = ( int * ) malloc ( N * sizeof ( int ) );
        int * tempc = ( int * ) malloc ( N * sizeof ( int ) );

        for (  i = 0; i < N; i++ )
        {
            scanf ( "%d", c + i );
            tempc[i] = c[i];
        }

        quickSort ( tempc, 0, N );

        for ( i = 0; i < N; i++ )
        {
            if ( binarySearch ( tempc, N, M - c[i] ) > 0 )
            {
                int k = i + 1;

                while ( c[k] + c[i] != M && k < N )
                {
                    k++;
                }

                if ( k < N )
                {
                    printf ( "%d %d\n", i+1, k+1 );
                    break;
                }
            }
        }
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
