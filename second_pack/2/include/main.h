#ifndef MAIN_H
#define MAIN_H
#include "validation.h"
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>


#define MAX_ERROR_MSG 128

// Проверка OS
#if defined(__APPLE__)
    #define OS_NAME "macOS"
    static const char *errorMessages[] = {
        "No error",                         // 0
        "Operation not permitted",          // 1
        "No such file or directory",        // 2
        "No such process",                  // 3
        "Interrupted system call",          // 4
        "Input/output error",               // 5
        "Device not configured",            // 6 (macOS)
        "Argument list too long",           // 7
        "Exec format error",                // 8
        "Bad file descriptor",              // 9
        "No child processes"                // 10
    };
#elif defined(__linux__)
    #define OS_NAME "Linux"
    static const char *errorMessages[] = {
        "Success",                          // 0
        "Operation not permitted",          // 1
        "No such file or directory",        // 2
        "No such process",                  // 3
        "Interrupted system call",          // 4
        "Input/output error",               // 5
        "No such device or address",        // 6 (Linux)
        "Argument list too long",           // 7
        "Exec format error",                // 8
        "Bad file descriptor",              // 9
        "No child processes"                // 10
    };
#else
    #error "Unsupported operating system"
#endif

#define ERROR_COUNT (sizeof(errorMessages) / sizeof(errorMessages[0]))



void *memchr(const void *str, int c, size_t n);
int memcmp(const void *str1, const void *str2, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *str, int c, size_t n);
char *strncat(char *dest, const char *src, size_t n);
char *strchr(const char *str, int c);
int strncmp(const char *str1, const char *str2, size_t n);
char *strncpy(char *dest, const char *src, size_t n);
size_t strcspn(const char *str1, const char *str2);
char *strerror(int errnum);
size_t strlen(const char *str);
char *strpbrk(const char *str1, const char *str2);
char *strrchr(const char *str, int c);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, const char *delim);

#endif