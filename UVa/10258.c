/*
 * UVa 10258
 * 09/11/16
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    uint8_t contestant;
    uint8_t problem;
    uint16_t time;
    uint8_t participate;
} result;

int main()
{
    int score_board[1000];

    int n, i;
    scanf("%d\n", &n);

    result results[100];

    while (n--) {

        for (i = 0; i < 100; i++) {
            results[i].contestant = i + 1;
            results[i].problem = 0;
            results[i].time = 0;
            results[i].participate = 0;
        }
        memset(score_board,
            0,
            1000 * sizeof(int));

        size_t len;
        ssize_t read;
        char* line = NULL;

        while ((read = getline(&line, &len, stdin)) != -1) {
            if (read < 3)
                break;

            int contestant, problem, time;
            char status;
            sscanf(line, "%d%d%d %c", &contestant, &problem, &time, &status);

            contestant--;
            results[contestant].participate = 1;

            if (status == 'I') {
                if (score_board[contestant * 10 + problem] <= 0)
                    score_board[contestant * 10 + problem] -= 20;
            }
            if (status == 'C') {
                if (score_board[contestant * 10 + problem] <= 0)
                    score_board[contestant * 10 + problem] = -score_board[contestant * 10 + problem] + time;
            }
        }

        int i;
        for (i = 0; i < 1000; i += 10) {

            int j;

            for (j = 0; j < 10; j++) {
                if (score_board[i + j] > 0) {
                    results[i / 10].problem++;
                    results[i / 10].time += score_board[i + j];
                }
            }
        }

        result temp_result;

        for (i = 0; i < 99; i++) {
            int j;
            for (j = i; j < 100; j++) {
                if (results[i].problem < results[j].problem) {
                    temp_result = results[i];
                    results[i] = results[j];
                    results[j] = temp_result;
                }
            }
        }

        for (i = 0; i < 99; i++) {
            int j;
            for (j = i; j < 100; j++) {
                if (results[i].problem == results[j].problem && results[i].time > results[j].time) {
                    temp_result = results[i];
                    results[i] = results[j];
                    results[j] = temp_result;
                }
            }
        }

        for (i = 0; i < 99; i++) {
            int j;
            for (j = i; j < 100; j++) {
                if (results[i].problem == results[j].problem
                    && results[i].time == results[j].time
                    && results[i].contestant > results[j].contestant) {
                    temp_result = results[i];
                    results[i] = results[j];
                    results[j] = temp_result;
                }
            }
        }

        for (i = 0; i < 100; i++) {
            if (results[i].participate) {
                printf("%d %d %d\n", results[i].contestant, results[i].problem, results[i].time);
            }
        }

        if (n) {
            printf("\n");
        }
    }

    return 0;
}
