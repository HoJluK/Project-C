#include "../s21_string.h"

size_t s21_strcspn(const char* str1, const char* str2) {
    size_t index = 0;
    size_t index2 = 0;
    int flag = 0;
    while ((str1[index] != '\0') && (!flag)){
        while ((str2[index2] != '\0') && (!flag)){
            if (str1[index] == str2[index2]) flag = 1;
            if (!flag) index2++;
        }
        index2 = 0;
        if (!flag) index++;
    }
    return index;
}

// int main() {
//     char *str1 = "hello world";
//     char *str2 = "lwrd";
//     int res = strcspn(str1,str2);
//     printf ("%d\n",res);
//     return 0;
// }