/*
 * CS 491
 * problem set #1
 * poj 1477
 *
 * Aug 30, 2016
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *nums = (int*)malloc(sizeof(int)*50);
    int set = 1;
    
    while(1) {
        int n;
        scanf("%d", &n);

        if(n <= 0) break;

        int sum = 0;

        for(int i = 0; i < n; i++) {
            scanf("%d", nums + i);
            sum += *(nums + i);
        }

        int avg = sum / n, res = 0;

        for(int i = 0; i < n; i++) {
            if(*(nums + i) > avg) {
                res += *(nums + i) - avg;
            }
        }

        printf("Set #%d\n", set++);
        printf("The minimum number of moves is %d.\n\n", res);
    }

    return 0;
}

