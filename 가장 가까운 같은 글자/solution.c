#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t get_strlen(const char *s) {
    size_t len = 0;
    
    while (s[len] != '\0')
        len++;
    return (len);
}


int* solution(const char* s) {
    size_t len = get_strlen(s);
    int* answer = (int *)calloc(sizeof(int), len);
    
    answer[0] = -1;
    for (int i = 1; i < len; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                answer[i] = i - j;
                break ;                
            }
        }
        if (answer[i] == 0)
            answer[i] = -1;
    }
    return (answer);
}