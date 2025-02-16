#include "../s21_string.h"

void *s21_strncpy(char *dest, const char *src, size_t n){
    char *destination = (char*)dest;
    char *source = (char*) src; 
    int flag = 0;
    for (int i = 0; i < n; i++){
        if (!flag) destination[i] = source[i]; 
        if (destination[i] == '\0') flag = 1;
        if (flag) destination[i] = '\0';
    }
}

// int main() {
//     char dest[50];
//     char *str = "hello";
//     size_t n = 7;
//     s21_strncpy(dest,str,n);
//     for (int i = 0; i < n; i++){
//         printf("%c",dest[i]);
//     }
//     return 0;
// }