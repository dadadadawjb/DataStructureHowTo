#ifndef STACK_BALANCE_H
#define STACK_BALANCE_H

#include <fstream>

#include "..\seqStack.h"

class balance {
private:
    ifstream fin;
    int currentLine;
    int Errors;
    struct Symbol {
        char Token;
        int TheLine;
    };
    enum CommentType{SlashSlash, SlashStar};

    bool CheckMatch(char Symbol1, char Symbol2, int Line1, int Line2);
    char GetNextSymbol();
    char NextChar();
    void PutBackChar(char ch);
    void SkipComment(enum CommentType type);
    void SkipQuote(char type);

public:
    balance(const char *s);
    int CheckBalance();
};

class noFile {};


#endif // STACK_BALANCE_H
