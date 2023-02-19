#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t get_strlen(const char *str) {
    size_t len = 0; 
    
    while (str[len] != '\0')
        len++;
    return (len);
}

unsigned int translate_char(const char *str, int i, int p_len) {
    unsigned int  num = 0;
    unsigned int point = i + p_len;
    
    while (i < point) {
        num *= 10;
        num += str[i] - 48;
        i++;
    }
    return (num);
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int answer = 0;
    int p_len = get_strlen(p);
    unsigned int *arr = (unsigned int *)calloc(sizeof(unsigned int), get_strlen(t) - p_len + 1);

    for (int i = 0; i < get_strlen(t) - p_len + 1; i++) {
        arr[i] = translate_char(t, i, p_len);
    }
    for (int i = 0; i < get_strlen(t) - p_len + 1; i++) {
        if (arr[i] <= translate_char(p, 0, get_strlen(p)))
            answer++;
    }
    return (answer);
}