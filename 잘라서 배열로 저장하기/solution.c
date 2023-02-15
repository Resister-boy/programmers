#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t get_strlen(const char *str) {
  size_t len = 0;

  while (str[len] != '\0')
    len++;
  return (len);
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_str, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int point;
    size_t total_len = get_strlen(my_str);
    int word_count = ((int)total_len / n) + 1;
    char** answer = (char**)malloc(sizeof(char *) * (word_count + 1));
    answer[word_count] = NULL;

    for (int i = 0; i < word_count; i++) {
      if (total_len > n) {
        answer[i] = (char *)calloc(sizeof(char), n + 1);
        point = n;
      }
      else {
        answer[i] = (char *)calloc(sizeof(char), total_len + 1);
        point = total_len;
      }
      for (int j = 0; j < point; j++) {
        answer[i][j] = (*my_str);
        mystr++;
        total_len--;
      }
    }
    return (answer);
}