#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t get_strlen(const char *str) {
    size_t len = 0;
    
    while (str[len] != '\0')
        len++;
    return (len);
}

bool check_skip(const char *skip, const char word) {
    for (int i = 0; skip[i]; i++) {
        if (skip[i] == word)
            return (true);
    }
    return (false);
}

char translate_word(const char word, char *src, int index, size_t len) {
    int diff;
    int i = 0;
    
    while (i < len) {
        if (src[i] == word) {
            if (len <= i + index) {
                diff = (i + index) % len;
                return (src[diff]);
            }
            break;
        }
        i++;
    }
    return (src[i + index]);
}


char* solution(const char* s, const char* skip, int index) {
    int a = 0;
    char *answer = (char *)calloc(sizeof(char), get_strlen(s) + 1);
    char *src = (char *)calloc(sizeof(char), 27 - get_strlen(skip));
    size_t src_len;
    for (int i = 97; i <= 122; i++) {
        if (check_skip(skip, (char)i) == false) {
            src[a] = (char)i;
            a++;            
        }
    }
    src_len = get_strlen(src);       
    for (int i = 0; s[i]; i++) {
        answer[i] = translate_word(s[i], src, index, src_len);
    }
    return (answer);
}