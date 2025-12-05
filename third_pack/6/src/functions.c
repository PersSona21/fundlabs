#include "../include/main.h"


static int match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}

static int openBrackets(char c){
    return (c == '(' || c == '<' || c == '{' || c == '[');
}

static int closeBrackets(char c){
    return (c == ')' || c == '>' || c == '}' || c == ']');
}


int check_brackets(const char *str){
    Stack *s = createStack(256);
    if (!s) return 0;

    for (size_t i = 0; str[i] != '\0'; i++){
        char c = str[i];

        if (openBrackets(c)){
            push(s, c);
        }
        else if (closeBrackets(c)){
            if (isEmpty(s)) {  // пустой стек — ошибка
                eraseStack(s);
                return 0;
            }
            char topChar = top(s); // теперь безопасно
            if (!match(topChar, c)){
                eraseStack(s);
                return 0;
            }
            pop(s);
        }
    }

    int result = isEmpty(s);
    // printf("%zu\n", s->index);
    eraseStack(s);
    return result;
}

