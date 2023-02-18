#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// cards1_len은 배열 cards1의 길이입니다.
// cards2_len은 배열 cards2의 길이입니다.
// goal_len은 배열 goal의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

size_t get_strlen(const char *str) {
    size_t len = 0;
    
    if (str == NULL)
        return (0);
    while (str[len] != '\0')
        len++;
    return (len);
}

int compare_str(const char *str1, const char *str2) {
    size_t i = 0;
    
    if (str1 == NULL || str2 == NULL)
        return (0);        
    while (str1[i] && str2[i] && str1[i] == str2[i])
        i++;        
    if (i == get_strlen(str1))
        return (1);
    return (0);
}

char* solution(const char* cards1[], size_t cards1_len, const char* cards2[], size_t cards2_len, const char* goal[], size_t goal_len) {
    size_t i = 0;
    size_t point = goal_len;
    char *answer = "No";
    
    while (i < goal_len && point) {
      if (cards1_len && compare_str(goal[i], *cards1)) {
        i++;  
        cards1++;
        cards1_len--;
      } else if (cards2_len && compare_str(goal[i], *cards2)) {
        i++;
        cards2++;
        cards2_len--;
      }
      point--;
    }
    if (i == goal_len)
      answer = "Yes";
    return (answer);
}