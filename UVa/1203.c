/*
 * UVa 1203
 * Sep 4, 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define DEBUG

int main() {
    int regs[3001];
    int i;

    memset(regs, -1, 3001 * sizeof(int));

    char temp[20];
    while(1) {
        gets(temp);
        if(temp[0] == '#') break;
        int r, p;
        sscanf(temp, "Register %d %d", &r, &p);
        regs[r] = p;
    }

    int regs_current[3001];
    memcpy(regs_current, regs, 3001 * sizeof(int));

    int k;
    scanf("%d", &k);

#ifdef DEBUG
    printf("k = %d\n", k);
    for(i = 0; i < 3001; i++) {
       if(regs[i] != -1) {
          printf("regs[%d] = %d\n", i, regs[i]);
       }
    }
#endif

    while(k) {
        int min = 3001;

        for(i = 0; i < 3001; i++) {
            if(regs[i] >= 0 && regs_current[i] < min) {
                min = regs_current[i];
            }
        }

        for(i = 0; i < 3001; i++) {
            if(regs_current[i] == min) {
                k--;
                printf("%d\n", i);
            }
            if(regs_current[i] > -1) {
                regs_current[i] -= min;
                if(regs_current[i] == 0) {
                    regs_current[i] += regs[i];
                }
            }
        }
    }

    return 0;
} 



