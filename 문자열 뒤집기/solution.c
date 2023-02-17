#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t get_strlen(const char *str) {
    size_t len = 0;
    
    while (str[len] != '\0')
        len++;
    return (len);
}

char *duplicate_str(const char *str) {
    int i = 0;
    char *new;

    new = (char *)calloc(sizeof(char), get_strlen(str) + 1);
    while (str[i] != '\0') {
        new[i] = str[i];
        i++;
    }
    return (new);
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    char temp;
    size_t len = get_strlen(my_string);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = duplicate_str(my_string);
    for (size_t i = 0; i < len / 2; i++) {
        temp = answer[i];
        answer[i] = answer[len - (i + 1)];
        answer[len - (i + 1)] = temp;
    }
    return (answer);
}