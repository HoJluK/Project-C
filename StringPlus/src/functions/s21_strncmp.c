#include "../s21_string.h"

int s21_strncmp (const char* str1, const char* str2, size_t n){
    int res = 0;
    int flag = 0;
    for (int i = 0; (i < n) && (!flag); i++){       
        if (str1[i] != str2[i]) {
            res = str1[i] - str2[i];
            flag = 1;
        }
        if ((str1[i] || str2[i]) == '\0'){
            flag = 1;
        }
    }
    return res;
}

// int main() {
//     char *str1 = "hello\0man";
//     char *str2 = "hel\0lomen";
//     int res = s21_strncmp (str1,str2,4);
//     printf("%d\n",res);
//     return 0;
// }