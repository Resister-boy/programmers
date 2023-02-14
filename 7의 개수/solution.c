#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *itoa(int num) {
  int len = 0;
  char *str;
  int n = num;
    
  while (n) {
    len++;
    n /= 10;
  }
  str = (char *)calloc(sizeof(char), len + 1);
  for (int i = len - 1; num; i--) {
    str[i] = num % 10 + 48;
    num /= 10;
  }
  return (str);
}

int get_total_len(char *str) {
  int i = 0;

  while (str[i] != '\0')
    i++;
  return (i);
}

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int a;
    int b = 0;
    char *str;
    int answer = 0;
    int total_len = 0;
    char **strs = (char **)malloc((array_len + 1));

    for (int i = 0; i < array_len; i++) {
      strs[i] = itoa(array[i]);
    }
    for (int i = 0; i < array_len; i++) {
      total_len += get_total_len(strs[i]);
    }
    str = (char *)calloc(sizeof(char), total_len + 1);
    for (size_t i = 0; i < array_len; i++) {
      a = 0;
      while (a < get_total_len(strs[i])) {
        str[b] = strs[i][a];
        b++;
        a++;
      }
    }
    for (int i = 0; i < total_len; i++) {
      if (str[i] == '7')
        answer++;
    }
    return (answer);
}