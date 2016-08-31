#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>

int32_t binarySearch ( int a[], int n, int key )
{
    int32_t low = 0, high = n - 1;
    int32_t mid;

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

    while ( a[low] > key && low >= 0 )
    {
        low--;
    }

    if ( low == n )
    {
        low --;
    }

    return low;
}

void swap ( int * x, int * y )
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int32_t choosePivot ( int32_t i, int32_t j )
{
    return ( ( i + j ) / 2 );
}

void quickSort ( int list[], int32_t m, int32_t n )
{
    int32_t key, i, j, k;

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

void printList ( int32_t list[], int32_t n )
{
    int32_t i;

    for ( i = 0; i < n; i++ )
    {
        printf ( "%d\t", list[i] );
    }
}

int64_t abs_int64 ( int64_t i )
{
    if ( i < 0 )
    {
        return -i;
    }
    else
    {
        return i;
    }
}

int main()
{
    int32_t N, Q;
    int * A, *x;

    scanf ( "%d", &N );
    A = ( int * ) malloc ( N * sizeof ( int ) );

    for ( int32_t i = 0; i < N; i++ )
    {
        scanf ( "%d", A + i );
    }

    scanf ( "%d", &Q );
    x = ( int * ) malloc ( Q * sizeof ( int ) );

    for ( int32_t i = 0; i < Q; i++ )
    {
        scanf ( "%d", x + i );
    }

    // printf ( "ordinaryInput: " );
    // printList ( A, N );

    // sort the list using quicksort
    quickSort ( A, 0, N - 1 );

    // printf ( "\nquickSort: " );
    // printList ( A, N );

    // printf ( "\n%d", binarySearch ( A, N, 0 ) );

    // calculate prefix sum
    int * prefixSum;
    prefixSum = ( int * ) malloc ( N * sizeof ( int64_t ) );
    *prefixSum = *A;

    for ( int32_t i = 1; i < N; i ++ )
    {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }

    // printf ( "\nprefixSum: " );
    // printList ( prefixSum, N );

    int64_t absoluteSum = 0;

    for ( int32_t i = 0; i < N; i++ )
    {
        absoluteSum += abs_int64 ( A[i] );
    }

    // printf ( "\nabsoluteSum = %d", absoluteSum );

    int64_t searchValue = 0;
    int32_t keyZero = binarySearch ( A, N, 0 );

    // printf ( "\nkeyZero = %d\n", keyZero );

    for ( int32_t i = 0; i < Q; i++ )
    {
        searchValue += x[i];
        int64_t tempAbsoluteSum = absoluteSum;
        int32_t keyValue = binarySearch ( A, N, -searchValue );

        if ( -searchValue < 0 )
        {
            int64_t temp = prefixSum[keyZero] - prefixSum[keyValue];

            tempAbsoluteSum -= abs_int64 ( temp );
            tempAbsoluteSum += abs_int64 ( temp + ( keyZero - keyValue ) * searchValue );

            tempAbsoluteSum -= ( keyValue + 1 ) * searchValue;
            tempAbsoluteSum += ( N - keyZero - 1 ) * searchValue;
        }

        if ( -searchValue > 0 )
        {
            int64_t temp = prefixSum[keyValue] - prefixSum[keyZero];

            searchValue = -searchValue;

            tempAbsoluteSum -= abs_int64 ( temp );
            tempAbsoluteSum += abs_int64 ( temp - ( keyValue - keyZero ) * searchValue );

            tempAbsoluteSum -= ( N - keyValue - 1 ) * searchValue;
            tempAbsoluteSum += ( keyZero + 1 ) * searchValue;

            searchValue = -searchValue;
        }

        printf ( "%lld\n", tempAbsoluteSum );

    }

    // printf ( "\n" );

    return 0;
}
