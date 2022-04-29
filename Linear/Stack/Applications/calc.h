#ifndef STACK_CALC_H
#define STACK_CALC_H

#include <cstring>
#include <cmath>

#include "..\seqStack.h"

class calc {
    char *expression;
    enum token{OPAREN, ADD, SUB, MULTI, DIV, EXP, CPAREN, VALUE, EOL};

    void BinaryOp(token op, seqStack<int> &dataStack);
    token getOp(int &value);

public:
    calc(char *s) {
        expression = new char[strlen(s)+1];
        strcpy(expression, s);
    }
    ~calc() {
        delete expression;
    }
    int result();
};


#endif // STACK_CALC_H
