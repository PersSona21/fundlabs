#include "../include/main.h"

void test(const char *str) {
    int ok = check_brackets(str);
    printf("\"%s\"  ->  %s\n", str, ok ? "OK" : "ERROR");
}

int main(int argc, char *argv[]) {
    // правильные строки
    test("()");
    test("([]){}");
    test("a*(b + [c - {d / <e>}])");
    test("<{[( )]}>");
    test("text without brackets");
    test("((((((((((((((((()))))))))))))))))");

    // неправильные строки
    test("(");
    test(")");
    test("([)]");
    test("{<[]>}}");
    test("{abc");
    test("([{}]>");

    // Пустая строка
    test("");
    // Верная но большая
    test("kasdhgisdhgposhfldsjfusdagf[sdhfupaynfasodhfi sduh gisugpoisaungonuasduiyfuoasdnfxoisdf'posaud f8ysdoifgysdp iugowi ygosdugo;isgh9sdygousyg08sy98fyg0as9d  gpshg piusdhgpo sduhgp9sdhg ishguhdsugpasduihgasdhgidshgdsjfsjdhfosidgouhgiuadshgjsdhgjsgkdsfjhposidhfpnsdhgosdhgosdhf87sgcklsdnfuyoasldulkjdgxghkjlhvi6ujhvciyukjnbbjyhnbjt]");
    return OK;
}
