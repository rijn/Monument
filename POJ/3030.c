/*
 * CS 491
 * Problem Set #1
 * poj 3030
 *
 * Aug 30, 2016
 */

#include <stdio.h>

int main() {
    
    int n;
    scanf("%d", &n);

    while(n--) {

        long r, e, c;
        scanf("%ld %ld %ld", &r, &e, &c);
        
        if(e-c > r) {
           printf("advertise\n");
        } else if(e-c == r) {
           printf("does not matter\n");
        } else {
           printf("do not advertise\n");
        }

    }

   return 0;
} 
