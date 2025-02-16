#include "../s21_string.h"
#include <errno.h>

char *s21_strerror(int errnum) {
    char *err = NULL;
    switch(errnum){
        case EPERM:
            err = "Operation not permitted";
            break;
        case ENOENT:
            err = "No such file or directory";
            break;
        case ESRCH:
            err = "No such process";
            break;
        case EINTR:
            err = "Interrupted system call";
            break;
        case EIO:
            err = "Input/output error";
            break;
        default:
            err = "Unknown error";
    }
    return err;
}

// int main() {
//     FILE *file = fopen ("fuck","r");
//     if (file == NULL){
//         printf ("%s\n", s21_strerror(errno));
//     }
//     return 0;
// }