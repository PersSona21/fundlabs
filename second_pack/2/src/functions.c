#include "../include/main.h"


/*Выполняет поиск первого
вхождения символа c (беззнаковый тип) в первых n байтах строки, на
которую указывает аргумент str. */
void *memchr(const void *str, int c, size_t n){
    if (!str || !n){
        return NULL;
    }
    unsigned char *p = (unsigned char *) str;
    unsigned char uc = (unsigned char) c;
    while(n > 0){
        if(uc == *p){
            return (void *) p;
        }
        ++p;
        --n;
    }
    return NULL;
}

/*Сравнивает
первые n байтов str1 и str2.*/
int memcmp(const void *str1, const void *str2, size_t n){
    if (!str1 || !str2){
        return 0;
    }
    const unsigned char *p1 = str1;
    const unsigned char *p2 = str2;
    while(n > 0){
        if(*p1 != *p2){
            return (int)*p1 - (int)*p2;
        }
        ++p1;
        ++p2;
        --n;
    }
    return 0;
}

/* Копирует n символов
из src в dest.
*/
void *memcpy(void *dest, const void *src, size_t n){
    if (!dest || !src){
        return NULL;
    }
    unsigned char *d = (unsigned char *) dest;
    const unsigned char *s = (const unsigned char *) src;

    for(size_t i = 0; i < n; ++i){
        *d++ = *s++;
    }

    return dest;
}

/*Копирует символ c (беззнаковый тип) 
в первые n символов строки, на которую указывает аргумент str.*/
void *memset(void *str, int c, size_t n){
    if (!str){
        return NULL;
    }
    unsigned char uc = (unsigned char) c;
    unsigned char *s = (unsigned char *) str;

    for(size_t i = 0; i < n; ++i){
        *s++ = uc;
    }

    return str;
}

/*Добавляет строку, на которую указывает
src, в конец строки, на которую указывает dest,
длиной до n символов.*/
char *strncat(char *dest, const char *src, size_t n){
    if (!dest || !src){
        return NULL;
    }
    char *d = dest;
    while (*d){
        d++;
    }

    size_t i = 0;
    while(i < n && src[i] != '\0'){
        d[i] = src[i];
        ++i;
    }
    d[i] = '\0';
    return dest;
}

/*Выполняет поиск первого вхождения символа c 
(беззнаковый тип) в строке, на которую указывает аргумент str.*/
char *strchr(const char *str, int c){
    if (!str){
        return NULL;
    }
    unsigned char uc = (unsigned char) c;
    const unsigned char *s = (const unsigned char *) str;

    while(*s){
        if (uc == *s){
            return (char *) s;
        }
        ++s;
    }
    if (uc == '\0')
        return (char *) s;
    
    return NULL;
}

/* Сравнивает не
более первых n байтов str1 и str2 */
int strncmp(const char *str1, const char *str2, size_t n){
    if (!str1 || !str2){
        return 0;
    }

    const char *s1 = str1;
    const char *s2 = str2;

    while(n > 0){

        if (*s1 == '\0' || *s2 == '\0'){
            return (int)*s1 - (int)*s2;
        }

        if (*s1 != *s2){
            return (int)*s1 - (int)*s2;
        }

        ++s1;
        ++s2;
        --n;
    }
    return 0;
}


/*Копирует до n
символов из строки, на которую указывает src, в dest. */
char *strncpy(char *dest, const char *src, size_t n){
    if (!dest || !src){
        return NULL;
    }
    char *d = dest;
    const char *s =  src;

    size_t i = 0;
    while(i < n && src[i] != '\0'){
        dest[i] = src[i];
        ++i;
    }
    // я добавил заполнение нулями до конца
    while(i < n){
        dest[i++] = '\0';
    }

    return dest;
}

/*Вычисляет длину начального сегмента str1, 
который полностью состоит из символов,
не входящих в str2.*/
size_t strcspn(const char *str1, const char *str2){
    size_t count = 0;
    if (!str1 || !str2){
        return 0;
    }
    for (const char *p1 = str1; *p1; p1++) {
        for (const char *p2 = str2; *p2; p2++) {
            if (*p1 == *p2) {
                return count;
            }
        }
        count++;
    }
    return count;
}

/*Выполняет поиск во внутреннем массиве
номера ошибки errnum и возвращает указатель на строку с сообщением
об ошибке. Нужно объявить макросы, содержащие массивы сообщений
об ошибке для операционных систем mac и linux. Описания ошибок есть
в оригинальной библиотеке. Проверка текущей ОС осуществляется с
помощью директив.*/
char *strerror(int errnum){
    static char unknownMsg[MAX_ERROR_MSG];

    if (errnum >= 0 && errnum < (int) ERROR_COUNT) {
        return (char *)errorMessages[errnum];
    } else {
        snprintf(unknownMsg, sizeof(unknownMsg), "Unknown error: %d", errnum);
        return unknownMsg;
    }
}

/*Вычисляет длину строки str, не включая
завершающий нулевой символ.*/
size_t strlen(const char *str){
    if (!str){
        return (size_t) 0;
    }
    size_t count = 0;
    const char *p = str;
    while (*p != '\0'){
        p++;
        count++;
    }

    return count;
}

/*Находит первый символ в
строке str1, который соответствует любому символу, указанному в str2.*/
char *strpbrk(const char *str1, const char *str2){
    if (!str1 || !str2){
        return (char *) NULL;
    }

    for(const char *p1 = str1; *p1 != '\0'; p1++){
        for(const char *p2 = str2; *p2 != '\0'; p2++){
            if (*p1 == *p2) return (char *) p1;
        }
    }
    return (char *) NULL;
}

/*Выполняет поиск последнего
вхождения символа c (беззнаковый тип) в строке, на которую указывает
аргумент str.*/
char *strrchr(const char *str, int c){
    if (!str){
        return (char *) NULL;
    }

    const unsigned char *p = (const unsigned char *) str;
    unsigned char uc = (unsigned char) c;

    const unsigned char *last = NULL;

    while (*p != '\0') {
        if (*p == uc) {
            last = p;
        }
        p++;
    }

    if (uc == '\0') {
        return (char *) p;
    }

    return (char *) last;
}

/*Находит первое вхождение всей строки 
needle (не включая завершающий нулевой
символ), которая появляется в строке haystack.*/
char *strstr(const char *haystack, const char *needle){
    if (!haystack || !needle){
        return (char *) NULL;
    }
    if (*needle == '\0') {
        return (char *)haystack;
    }

    const char *h, *n;

    while (*haystack != '\0') {
        h = haystack;
        n = needle;

        while (*h != '\0' && *n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack;
        }

        haystack++;
    }

    return (char *) NULL;

}

/*Разбивает строку str на ряд
токенов, разделенных delim.*/
char *strtok(char *str, const char *delim){
    if (!delim){
        return (char *) NULL;
    }

    static char *next = NULL;
    if (str != NULL)
        next = str;

    if (next == NULL)
        return (char *) NULL;

    while (*next && strchr(delim, *next))
        next++;

    if (*next == '\0')
        return NULL;

    char *start = next;

    while (*next && !strchr(delim, *next))
        next++;

    if (*next) {
        *next = '\0';
        next++;
    }

    return start;
}