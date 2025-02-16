#include "../s21_string.h"

char *s21_strchr (const char* str, int ch){
    char* ptr = NULL;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == ch){
            ptr = (char*)str + i;
        } 
    }
    return ptr;
}

// int main() {
//     char *str = "hello";
//     int ch = 'e';
//     char *ptr = s21_strchr(str,ch);
//     printf("%c",*ptr);
//     return 0;
// }