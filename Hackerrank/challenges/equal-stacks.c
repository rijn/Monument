#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <inttypes.h>

int main(){
    int32_t n1; 
    int32_t n2; 
    int32_t n3; 
    int32_t th1 = 0, th2 = 0, th3 = 0;
    scanf("%d %d %d",&n1,&n2,&n3);
    int32_t *h1 = malloc(sizeof(int32_t) * n1);
    for(int32_t h1_i = 0; h1_i < n1; h1_i++){
       scanf("%d",&h1[h1_i]);
        th1 += h1[h1_i];
    }
    int32_t *h2 = malloc(sizeof(int32_t) * n2);
    for(int32_t h2_i = 0; h2_i < n2; h2_i++){
       scanf("%d",&h2[h2_i]);
        th2 += h2[h2_i];
    }
    int32_t *h3 = malloc(sizeof(int32_t) * n3);
    for(int32_t h3_i = 0; h3_i < n3; h3_i++){
       scanf("%d",&h3[h3_i]);
        th3 += h3[h3_i];
    }
    int32_t tn1 = n1, tn2 = n2, tn3 = n3;
    while(tn1 > 0 && tn2 > 0 && tn3 > 0 && !(th1 == th2 && th1 == th3)) {
        //printf("%d %d %d\n", th1, th2, th3);
        if(th3 >= th1 && th3 >= th2) {
            tn3 --;
            th3 -= h3[n3 - tn3 - 1];
        } else if(th2 >= th1 && th2 >= th3) {
            tn2 --;
            th2 -= h2[n2 - tn2 - 1];
        } else {
            tn1 --;
            th1 -= h1[n1 - tn1 - 1];
        }
    }
    if(tn1 == 0 || tn2 == 0 || tn3 == 0) {
        printf("0");
    } else {
        printf("%d", th1);
    }
    return 0;
}
