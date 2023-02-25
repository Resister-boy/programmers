#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a) {
        n = n - a + b;
        answer += b;
    }
    return (answer);
}