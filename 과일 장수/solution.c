#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_len은 배열 score의 길이입니다.
int solution(int k, int m, int score[], size_t score_len) {
    int answer = 0;
    bool *check_list = calloc(sizeof(bool), score_len);
    int len = (score_len / m) * m;
    int num = k;
    int i = 0;
    
    while (i < len) {
        for (int j = 0; j < score_len; j++) {
           if (!check_list[j] && score[j] == num) {
               check_list[j] = true;
               i++;
               if (i % m == 0)
                   answer += num * m;
           } 
            if (j == score_len - 1) 
                num--;
        }
    }

    return (answer);
}
