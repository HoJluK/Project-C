#include "../s21_string.h"

void itoa(int value, char *str) {
    int i = 0;
    int negative = 0;
    if (value < 0) {
        negative = 1;
        value = -value;
    }
    while (value > 0) {
        str[i++] = (value % 10) + 48;
        value /= 10;
    }
    if (negative) {
        str[i++] = '-';
    }
    str[i] = '\0';
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
}

int s21_sprintf(char *buffer, const char *format, ...) {
    va_list args;                 // Объект для работы с аргументами
    va_start(args, format);       // Инициализируем переменные аргументы
    char *buf_ptr = buffer;       // Указатель для записи в буфер
    for (const char *ptr = format; *ptr != '\0'; ptr++) {
        if (*ptr == '%') {        // Проверяем спецификатор
            ptr++;                // Переходим к следующему символу
            switch (*ptr) {
                case 'd': {       // Целое число
                    int value = va_arg(args, int);
                    char num_str[20]; // Буфер для целого числа
                    itoa(value, num_str); // Преобразуем число в строку
                    // Копируем строку в буфер
                    char *temp = num_str;
                    while (*temp) {
                        *buf_ptr = *temp;
                        buf_ptr++;
                        temp++;                    }
                    break;
                }
                case 's': {       // Строка
                    char *str = va_arg(args, char *);
                    while (*str) {
                        *buf_ptr++ = *str++;
                    }
                    break;
                }
                case 'c': {       // Символ
                    char c = (char)va_arg(args, int);
                    *buf_ptr++ = c;
                    break;
                }
                case '%': {       // Символ '%'
                    *buf_ptr++ = '%';
                    break;
                }
                default:          // Неизвестный спецификатор
                    *buf_ptr++ = '%';
                    *buf_ptr++ = *ptr;
                    break;
            }
        } else {
            *buf_ptr++ = *ptr;    // Копируем обычный символ
        }
    }
    *buf_ptr = '\0';              // Завершаем строку
    va_end(args);                 // Завершаем работу с аргументами
    return (int)(buf_ptr - buffer); // Возвращаем количество записанных символов
}

int main() {
    char buffer[256];
    int length = s21_sprintf(buffer, "Hello, %s! Your number is %d and character is %c.", "World", 42, 'A');
    printf("Formatted string: %s\n", buffer);
    printf("Length: %d\n", length);
    return 0;
}

