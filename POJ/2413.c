/*
 * POJ 2413
 * Sep 4, 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define DEBUG

#define N 101

char* add(char* a, char* b) {
    char* temp = (char*)malloc(N * sizeof(char));
    memset(temp, '0', N);
    int i;

    for(i = 0; i < N; i++) {
        int _a = *(a + i) - '0';
        int _b = *(b + i) - '0';
        int _c = *(temp + i) - '0';

        *(temp + i) = (_a + _b + _c) % 10 + '0';
        *(temp + i + 1) = (_a + _b + _c) / 10 + '0';
    }

    return temp;
};

/*
 * int compare(char* a, char* b)
 *
 * compare two positive numbers
 * if(a>b) return 1;
 * if(a<b) return -1;
 * if(a==b) return 0;
 */
int compare(char* a, char* b) {

    int i = 0;

    for(i = N - 1; i >= 0; i--) {
        if(a[i] > b[i]) {
            return 1;
        }
        if(a[i] < b[i]) {
            return -1;
        }
    }
    return 0;
}

void print_num(char* a) {
    
    int i = N - 1;
    while(a[i] == '0') i--;
    for(; i >=0; i--) {
        printf("%c", a[i]);
    }

    printf("\n");
    
    return;
}

int main() {

    char** fibs = (char**)malloc(2 * sizeof(char*));
    char*  pivot = (char*)malloc(N * sizeof(char));

    memset(pivot, '0', N);
    pivot[N - 1] = '1';

#ifdef DEBUG
    print_num(pivot);
#endif

    *(fibs + 0) = (char*)malloc(N * sizeof(char));
    *(fibs + 1) = (char*)malloc(N * sizeof(char));

    memset(*(fibs + 0), '0', N);
    memset(*(fibs + 1), '0', N);

    **(fibs + 0) = '1';
    **(fibs + 1) = '1';

    int i = 1;
    while(compare(pivot, *(fibs + i)) == 1) {
        fibs = (char**)realloc(fibs, (i + 2) * sizeof(char*));
        *(fibs + i + 1) = (char*)add(*(fibs + i), *(fibs + i - 1));
        i++;
#ifdef DEBUG
        print_num(*(fibs + i));
#endif
    }
    int fibs_length = i;

    char input_a[N], input_b[N];

    char* num_a = (char*)malloc(N * sizeof(char));
    char* num_b = (char*)malloc(N * sizeof(char));

    while(1) {
        scanf("%s%s", input_a, input_b);
        if(!(strcmp(input_a, "0") || strcmp(input_b, "0"))) {
            break;
        }

        memset(num_a, '0', N);
        memset(num_b, '0', N);

        int len = strlen(input_a);
        for(i = len - 1; i >= 0; i--) {
            num_a[len - i - 1] = input_a[i];
        }

        len = strlen(input_b);
        for(i = len - 1; i >= 0; i--) {
            num_b[len - i - 1] = input_b[i];
        }

#ifdef DEBUG
        printf("input a: ");
        print_num(num_a);
        printf("input b: ");
        print_num(num_b);
#endif

        int pivot_a = 0;
        int pivot_b = 0;

        while(compare(num_a, *(fibs + pivot_a)) == 1 && pivot_a < fibs_length - 1) {
            pivot_a++;
        }
        
        pivot_b = pivot_a;

        while(compare(num_b, *(fibs + pivot_b)) != -1 && pivot_b < fibs_length - 1) {
            pivot_b++;
        }

#ifdef DEBUG
        printf("pivot_a [%d], pivot_b [%d]\n", pivot_a, pivot_b);
#endif

//         if(compare(num_b, *(fibs + pivot_b - 1)) == 0) {
//             pivot_b++;
// #ifdef DEBUG
//             printf("num_b equal\n");
// #endif
//         }
        if(pivot_a > 0 && compare(num_a, *(fibs + pivot_a - 1)) == 0) {
            pivot_b++;
#ifdef DEBUG
            printf("num_a equal\n");
#endif
        }

        if(pivot_b == 0) {
            pivot_b = 2;
        }

        printf("%d\n", pivot_b - pivot_a);

    }    

    for(i = 0; i < fibs_length; i++) {
        free(fibs[i]);
    }
    free(fibs);
    free(num_a);
    free(num_b);
    free(pivot);

    return 0;
}

