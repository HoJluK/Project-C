#include "s21_string.h"

int s21_memcmp (const void *str1, const void *str2, s21_size_t n)
{
    int res = 0;
    int flag = 0;
    char *func_str1 = (char*)str1;
    char *func_str2 = (char*)str2;
    for (s21_size_t i = 0; (i < n) && (!flag); i++) {
        if (func_str1[i] != func_str2[i]){
            res = func_str1[i] - func_str2[i];
            flag = 1;
        }
    }
    return res;
}

// int main() {
//     char *str = "hello man";
//     char *str2 = "man hello";
//     size_t len = 2;
//     int res = 0;
//     res = s21_memcmp(str,str2,len);
//     printf("%d",res);
//     return 0;
// }