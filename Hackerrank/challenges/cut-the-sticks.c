#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>

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

void printList ( int list[], int n )
{
    int i;

    for ( i = 0; i < n; i++ )
    {
        printf ( "%d\t", list[i] );
    }
}

int main()
{
    int n;
    scanf ( "%d", &n );
    int arr[n];

    for ( int arr_i = 0; arr_i < n; arr_i++ )
    {
        scanf ( "%d", &arr[arr_i] );
    }

    quickSort ( arr, 0, n-1 );

    int temp = arr[0];
    printf ( "%d\n", n );

    for ( int i = 0; i < n; i++ )
    {
        if ( temp != arr[i] )
        {
            printf ( "%d\n", n - i );
            temp = arr[i];
        }
    }

    return 0;
}
