#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

const char *babbling[6] = {
"ayaaya", "uuuma", "ye", "mama", "ayaa",
  NULL
};

const size_t babbling_len = 5;


int	ft_strncmp(char **dest, char *src, size_t ptr, size_t len, int *dup) {
	size_t	i;
    size_t  j;

	i = 0;
    j = ptr;
	while ((*dest)[j] == src[i] && i < len && src[i]) {
		i++;
        j++;
    }
    j = 0;
    if (src[i] == '\0' && (*dup) == 1) {
        while (j < strlen(src)) {
            (*dest)[ptr] = ' ';
            j++;
            ptr++;
        }
        (*dup)--;
        return (1);
    }
    return (0);
}

bool find_word(const char *babbling, char *babb_list[]) {
    size_t i = 0;
    size_t k = 0;
    size_t j;
    int dup[4] = {1, 1, 1, 1};
    char *babbling_cpy = strdup(babbling);
    while (babbling_cpy[i] != '\0') {
        j = 0;
        while (babb_list[j]) {
            if (ft_strncmp(&babbling_cpy, babb_list[j], k, strlen(babb_list[j]), &(dup[j])))
                k += strlen(babb_list[j]);
            j++;
        }
        i += k;
        if (i == 0)
            return (false);
    }
    i = 0;
    while (babbling_cpy[i] != '\0') {
        if (babbling_cpy[i] !=  ' ')
            return (false);
        i++;
    }
  return (true);
}

int solution(const char* babbling[], size_t babbling_len) {
    char *babb_list[5] = {"aya", "ye", "woo", "ma", NULL};
    size_t i = 0;
    int answer = 0;
    while (i < babbling_len) {
        if (find_word(babbling[i], babb_list))
            answer++;
        i++;
    }
    return answer;
}