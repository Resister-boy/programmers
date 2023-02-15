#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int point_n(int n, int numlist[], size_t numlist_len) {
    int num = 0;
    
    for (int i = 0; i < numlist_len; i++) {
        if ((numlist[i] % n) == 0)
            num++;
    }
    return (num);
}

// numlist_len은 배열 numlist의 길이입니다.
int* solution(int n, int numlist[], size_t numlist_len) {
    int a = 0;;
    int num = point_n(n, numlist, numlist_len);
    printf("num: %d\n", num);
    int *answer = (int *)calloc(sizeof(int), num);
    for (int i = 0; i < numlist_len; i++) {
        if ((numlist[i] % n) == 0) {
            answer[a] = numlist[i];
            a++;
        }
    }
    return (answer);
}