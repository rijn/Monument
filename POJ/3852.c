/*
 * POJ3852
 * Sep 4, 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define DEBUG

int main() {
    
    int n;

    while(~scanf("%d", &n) && n) {

        char **str = (char**)malloc(n * sizeof(char*));
        int i;
        for(i = 0; i < n; i++) {
            *(str + i) = (char*)malloc(101 * sizeof(char));
            memset(*(str + i), '\0', 101);
            scanf("%s", *(str + i));
#ifdef DEBUG
            printf("%s\n", *(str + i));
#endif
        }


        int times = 0;
        char flag = 0;
        while(1) {

            for(i = 0; i < n; i++) {
                if(!strcmp(*(str + i), "")) {
                    flag = 1;
                }
                int j;
                for(j = i + 1; j < n; j++) {
                    if(!(strcmp(*(str + i), *(str + j)))) {
                        flag = 1;
                    }
                }
            }

            if(flag) break;

            for(i = 0; i < n; i++) {
                *(str + i) = *(str + i) + 1;
            }

            times++;

        }

        printf("%d\n", times - 1);

        free(str);
    }

    return 0;
}

