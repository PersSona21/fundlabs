#ifndef MAIN_H
#define MAIN_H
#include "validation.h"
#include "stack.h"
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

static int Match(char open, char close);
static int openBrackets(char c);
static int closeBrackets(char c);
int check_brackets(const char *str);

#endif