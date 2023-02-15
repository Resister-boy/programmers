#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *itoa(int num) {
    char *str;
    int n = num;
    int len = 0;
    
    while (n) {
        n /= 10;
        len++;
    }
    str = (char *)calloc(sizeof(char), len + 1);
    while (num) {
        len--;
        str[len] = num % 10 + 48;
        num /= 10;
    }
    return (str);
}

int solution(int num, int k) {
    int answer = -1;
    char *str = itoa(num);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((int)str[i] - 48 == k) {
            return (i + 1);
        }
    }
    return (answer);
}