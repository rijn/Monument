/*
 * CS 491
 * problem set #1
 * poj 1338
 *
 * Aug 30, 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    
    int temp = a;
    if(b < temp) {
        temp = b;
    }
    if(c < temp) {
        temp = c;
    }

    return temp;
}

int main() {
//    char flag_array[3000];
//
//    memset(flag_array, 0, 3000 * sizeof(char));
//
//    int i;
//
//    for(i = 0; i < 3000/2; i++) {
//        flag_array[i*2] = 1;
//    }
//
//    for(i = 0; i < 3000/3; i++) {
//        flag_array[i*3] = 1;
//    }
//
//    for(i = 0; i < 3000/5; i++) {
//        flag_array[i*5] = 1;
//    }
//
//    flag_array[1] = 1;
//    flag_array[0] = 0;

    int a2 = 1,
        a3 = 1,
        a5 = 1,
        i, tmp, n;

    int ugly_numbers[1501];
    ugly_numbers[1] = 1;

    for(i = 2; i < 1501; i++) {
        tmp = min(ugly_numbers[a2] * 2, ugly_numbers[a3] * 3, ugly_numbers[a5] * 5);
        ugly_numbers[i] = tmp;
        if(tmp == ugly_numbers[a2] * 2) a2 ++;
        if(tmp == ugly_numbers[a3] * 3) a3 ++;
        if(tmp == ugly_numbers[a5] * 5) a5 ++;
    }

//    for(i = 0; i < 3000; i++) {
//        if(flag_array[i]) {
//            // printf("%d\t", i);
//            ugly_numbers[++ugly_numbers[0]] = i;
//        }   
//    }

    while(1) {
        scanf("%d", &i);
        if(!i) break;
        printf("%d\n", ugly_numbers[i]);
    }

    return 0;
}
