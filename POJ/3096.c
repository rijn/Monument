/*
 * CS 491
 * Problem Set #1
 * poj 3096
 *
 * Aug 30, 2016
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    char *word = (char*)malloc(sizeof(char) * 80);

    while(1) {

        scanf("%s", word);
        if(word[0] == '*') break;

        int len = 0;
        char *ptr = word;
        for(; *ptr != '\0'; ptr++ && len++);

        char flag = 1;

        for(int i = 1; i < len - 1 && flag; i++) {
            for(int j = 0; j < len - i - 1 && flag; j++) {
                for(int k = j+1; k < len - i && flag; k++) {
                    if(word[j] == word[k] && word[j+i] == word[k+i]) {
                        flag = 0;
                    }
                }
            }
        }

        if(flag) {
            printf("%s is surprising.\n", word);
        } else {
            printf("%s is NOT surprising.\n", word);
        }
    }

    return 0;
}

