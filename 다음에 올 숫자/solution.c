#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int check_type(int common[], size_t common_len) {
    int diff_a;
    int diff_b;
    if (!common)
        return (-1);
    diff_a = common[common_len - 1] - common[common_len - 2];
    diff_b = common[common_len - 2] - common[common_len - 3];
    if (diff_a == diff_b)
        return (0);
    return (1);
}

int solution(int common[], size_t common_len) {
    int answer = 0;
    int value = check_type(common, common_len);
    if (value == 0)
        answer = common[common_len - 1] + (common[common_len - 1] - common[common_len - 2]);
    else if (value == 1)
        answer = common[common_len - 1] * (common[common_len - 1] / common[common_len - 2]);
    return (answer);
}