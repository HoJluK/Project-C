#include "../s21_string.h"

char *s21_strrchr (const char* str, int ch) {
    size_t index;
    char *ptr = NULL;
    while (str[index]!='\0'){
        if (str[index] == ch){
            ptr = (char*)str + index;
        }
        index++;
    }
    return ptr;
}

// int main() {
//     char *str = "hello world";
//     int ch = 'o';
//     char *ptr = s21_strrchr(str,ch) + 1;
//     printf("%c",*ptr);
//     return 0;
// }