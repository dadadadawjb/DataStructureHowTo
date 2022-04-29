#include "calc.h"

int calc::result() {
    token lastOp, topOp;
    int resultValue, currentValue;
    seqStack<token> opStack;
    seqStack<int> dataStack;
    char *str = expression;

    while ((lastOp = getOp(currentValue)) != EOF) {
        switch (lastOp) {
            case VALUE: dataStack.push(currentValue); break;
            case CPAREN:
                while (!opStack.isEmpty() && (topOp = opStack.pop()) != OPAREN)
                    BinaryOp(topOp, dataStack);
                if (topOp != OPAREN)
                    cerr << "lack of OPAREN!" <<endl;
                break;
            case OPAREN: opStack.push(OPAREN); break;
            case EXP: opStack.push(EXP); break;
            case MULTI:
            case DIV:
                while (!opStack.isEmpty() && opStack.top() >= MULTI)
                    BinaryOp(opStack.pop(), dataStack);
                opStack.push(lastOp);
                break;
            case ADD:
            case SUB:
                while (!opStack.isEmpty() && opStack.top() != OPAREN)
                    BinaryOp(opStack.pop(), dataStack);
                opStack.push(lastOp);
        }
    }

    while (!opStack.isEmpty())
        BinaryOp(opStack.pop(), dataStack);

    if (dataStack.isEmpty()) {
        cout << "no result" << endl;
        return 0;
    }
    resultValue = dataStack.pop();

    if (!dataStack.isEmpty()) {
        cout << "lack of op" << endl;
        return 0;
    }

    expression = str;
    return resultValue;
}

void calc::BinaryOp(token op, seqStack<int> &dataStack) {
    int num1, num2;

    if (dataStack.isEmpty()) {
        cerr << "lack of right op!" << endl;
        exit(1);
    } else {
        num2 = dataStack.pop();
    }

    if (dataStack.isEmpty()) {
        cerr << "lack of left op!" << endl;
        exit(1);
    } else {
        num1 = dataStack.pop();
    }

    switch (op) {
        case ADD: dataStack.push(num1 + num2); break;
        case SUB: dataStack.push(num1 - num2); break;
        case MULTI: dataStack.push(num1 * num2); break;
        case DIV: dataStack.push(num1 / num2); break;
        case EXP: dataStack.push(pow(num1, num2));
    }
}

calc::token calc::getOp(int &value) {
    while (*expression && *expression == ' ')
        expression++;
    if (*expression == '\0')
        return EOL;

    if (*expression <= '9' && *expression >= '0') {
        value = 0;
        while (*expression >= '0' && *expression <= '9') {
            value = value*10 + *expression - '0';
            expression++;
        }
        return VALUE;
    }

    switch (*expression) {
        case '(': expression++; return OPAREN;
        case ')': expression++; return CPAREN;
        case '+': expression++; return ADD;
        case '-': expression++; return SUB;
        case '*': expression++; return MULTI;
        case '/': expression++; return DIV;
        case '^': expression++; return EXP;
    }
}