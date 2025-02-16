#include "../s21_string.h"

char *s21_strstr(const char* str, const char* substr){
    char *ptr = NULL;
    int match = 0;
    int flag = 0;
    size_t count = 0;
    for (int i = 0; (i < strlen(str)) && (!flag); i++){
        if (str[i] == substr[count]){
            match = 1;
            count++;
        } else {
            match = 0;
            count = 0;
        }
        if (count == strlen(substr)) { //поменяй потом на s21_strlen
            ptr = (char*)str +(i-count+1);
            flag = 1;
        }
    }
    return ptr;
}

// int main() {
//     char *str = "trick or treat";
//     char *substr = "treat";
//     char *ptr = strstr(str,substr);
//     printf ("%s", ptr);
//     return 0;
// }