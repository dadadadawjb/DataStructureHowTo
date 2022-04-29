#ifndef LIST_LONGLONGINT_H
#define LIST_LONGLONGINT_H

#include <iostream>
#include <cstring>
using namespace std;

class LongLongInt {
    friend ostream &operator<<(ostream &os, const LongLongInt &obj);
    friend LongLongInt operator+(const LongLongInt &n1, const LongLongInt &n2);
    friend LongLongInt operator-(const LongLongInt &n1, const LongLongInt &n2);

private:
    char sign;
    char *num;

public:
    LongLongInt(const char *n="");
    LongLongInt(const LongLongInt &other);
    LongLongInt &operator=(const LongLongInt &right);
    ~LongLongInt()
    {
        delete num;
    }
};

char *add(const char *s1, const char *s2);
char *sub(const char *s1, const char *s2);
bool greaterThan(const char *s1, const char *s2);

#endif // LIST_LONGLONGINT_H
