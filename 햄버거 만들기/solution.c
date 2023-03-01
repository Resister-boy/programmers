#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ingredient_len은 배열 ingredient의 길이입니다.
int solution(int ingredient[], size_t ingredient_len) {
    int answer = 0;
    int j;

    for (int i = 1; i < ingredient_len; i++) {
        if ((ingredient[i - 1] == 1) \
           && (ingredient[i] == 2) \
           && (ingredient[i + 1] == 3) \
           && (ingredient[i + 2] == 1)) {
            j = i - 1;
            for (int k = i + 3; k < ingredient_len; k++) {
                ingredient[j] = ingredient[k] ;
                j++;
            }
            ingredient_len -= 4;
            answer++;
            j = 0;
            i -= 3;
            if (i < 0)
                i = 0;
        }
    }    

    return answer;
}