#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int number, int limit, int power) {
    int answer = 0;
    int stat;
    int op;
    
    for (int i = 1; i <= number; i++) {
        op = 0;
        stat = 0;
        for (int j = 1; j * 2 <= i; j++) {
            if (i % j == 0)
                op++;
            if (j * 2 == i)
                stat++;
        }
        if (i > 1 || stat == 0)
            op++;
        if (limit < op)
            op = power;
        answer += op;
    }
    return answer;
}