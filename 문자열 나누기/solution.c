#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

size_t get_strlen(const char *str) {
    size_t len = 0; 
    
    while (str[len] != '\0')
        len++;
    return (len);
}

int solution(const char* s) {
    int answer = 0;
    int count = 0;
    char start;
    int same = 0;
    int diff = 0;

    start = s[count];
    while(count < strlen(s)) {
        if(start == s[count])
            same++;
        else
            diff++;
        if(same == diff) {
            answer++;
            count++;
            start = s[count];
            same = 0; diff = 0;
        } else {
            count++;
            if(count == get_strlen(s)) {
                answer++;
                break;
            }
        }
    }
    return (answer);
}
