#include "../s21_string.h"

size_t s21_strlen (const char* str) {
    size_t index = 0;
    while (str[index]!='\0'){
        index++;
    }
    return index;
}

// int main() {
//     char *str = "help me";
//     int i = s21_strlen(str);
//     printf("%d",i);
//     return 0;
// }