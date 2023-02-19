#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void translate_date(const char *str, int *year, int *month, int *day) {
    int i = 0;
    int status = 0;
    
    while ((str[i] != '\0' || str[i] != ' ') && status < 2) {
        if (str[i] == '.' && status == 0) {
            (*year) = (str[i - 2] - 48) * 10 + (str[i - 1] - 48);
            status++;
        } else if (str[i] == '.' && status == 1) {
            (*month) = (str[i - 2] - 48) * 10 + (str[i - 1] - 48);
            (*day) = (str[i + 1] - 48) * 10 + (str[i + 2] - 48);
            status++;
        }
        i++;
    }
}

int check_type(const char **type, size_t len, const char *privacy) {
    char type_number;
    int duration = 0;
    
    for (int i = 0; i < len; i++) {
        if (type[i][0] == privacy[11]) {
            type_number = i;
            break;            
        }
    }
    for (int i = 0; type[type_number][i]; i++) {
        if (type[type_number][i] >= '0' && type[type_number][i] <= '9') {
            duration *= 10;
            duration += (type[type_number][i] - 48);
        }
    }
    return (duration);
}

int compare_date(int t_year, int t_month, int t_day, int p_year, int p_month, int p_day) {
    int result;
    
    if (t_year < p_year)
        result = 0;
    else if (t_year > p_year)
        result = 1;
    else {
        if (t_month < p_month)
            result = 0;
        else if (t_month > p_month)
            result = 1;
        else {
            if (t_day < p_day)
                result = 0;
            else result = 1;
        }
    }
    return (result);
}

int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len) {
    int *answer;
    size_t len = 0;
    int t_year, t_month, t_day;
    int p_year, p_month, p_day;
    int *p_status = (int *)calloc(sizeof(int), privacies_len);
    int duration;
    
    for (int i = 0; i < privacies_len; i++) {
        translate_date(today, &t_year, &t_month, &t_day);
        duration = check_type(terms, terms_len, privacies[i]);
        if (duration >= 12) {
            if (duration % 12 == 0) {
                t_year -= duration / 12;
            } else {
                if (t_month <= duration % 12) {
                    t_year -= (duration / 12 + 1);
                    t_month += 12 - (duration % 12);
                } else {
                    t_year -= duration / 12;
                    t_month -= duration % 12;
                }
            }
        } else {
            if (t_month <= duration % 12) {
                t_year -= 1;
                t_month += 12 - (duration % 12);
            } else {
                t_month -= duration % 12;
            }
        }
        translate_date(privacies[i], &p_year, &p_month, &p_day);
        if (compare_date(t_year, t_month, t_day, p_year, p_month, p_day)) {
            p_status[i] = 1;
            len++;
        }
    }
    answer = (int)calloc(sizeof(int), len);
    len = 0;
    for (int i = 0; i < privacies_len; i++) {
        if (p_status[i] == 1) {
            answer[len] = i + 1;
            len++;            
        }
    }
    return (answer);
}