#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int find_min(int a, int b) {
    int min;
    
    if (a < b)
        min = a;
    else if (a > b)
        min = b;
    else
        min = a;
    return (min);
}

bool check_zero(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] != '0')
            return (false);
    }
    return (true);
}

char* solution(const char* X, const char* Y) {
    int col = 0;
    char temp;
    char *answer;
    int x_arr[10] = {0};
    int y_arr[10] = {0};
    
    for (int i = 0; X[i]; i++) {
        temp = X[i];
        x_arr[temp - 48]++;
    }
    for (int i = 0; Y[i]; i++) {
        temp = Y[i];
        y_arr[temp - 48]++;
    }
    for (int i = 0; i < 10; i++) {
        col += find_min(x_arr[i], y_arr[i]);
    }
    answer = (char *)calloc(sizeof(char), col + 1);
    if (col == 0)
        return ("-1");
    for (int i = 0; i < 10; i++) {
        if (x_arr[i] != 0 && y_arr[i] != 0) {
            for (int j = 0; j < find_min(x_arr[i], y_arr[i]); j++) {
                answer[col -1] = i + 48;
                col--;
            }
        }
    }
    if (check_zero(answer) == true)
        return ("0");
    return (answer);
}