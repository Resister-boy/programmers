#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t get_strlen(const char *str) {
  size_t len = 0;

  while (str[len])
    len++;
  return (len);
}

char *duplicate_str(const char *str) {
  int i = 0;
  char *new = (char *)calloc(sizeof(char), get_strlen(str) + 1);
  
  while (str[i] != '\0') {
    new[i] = str[i];
    i++;
  }
  return (new);
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    size_t len = get_strlen(my_string);
    char* answer = duplicate_str(my_string);
    char temp;

    for (int i = 0; i < get_strlen(my_string); i++) {
      if (answer[i] >= 65 && answer[i] <= 90)
        answer[i] += 32;
    }
    for (int i = 0; i < get_strlen(my_string); i++) {
      for (int j = 1; j < get_strlen(my_string) - i; j++) {
        if (answer[j - 1] > answer[j]) {
          temp = answer[j - 1];
          answer[j - 1] = answer[j];
          answer[j] = temp;
        }
      }
    }
    return (answer);
}

int main(void) {
  char *answer;
  const char *str;

  str = "Hello";
  answer = solution(str);
  printf("answer: %s\n", answer);
  return (0);
}