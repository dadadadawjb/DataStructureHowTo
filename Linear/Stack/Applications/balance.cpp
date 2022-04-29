#include "balance.h"

balance::balance(const char *s) {
    fin.open(s);
    if (!fin)
        throw noFile();
    currentLine = 1;
    Errors = 0;
}

int balance::CheckBalance() {
    struct Symbol node;
    seqStack<Symbol> st;
    char LastChar, Match;
    
    while (LastChar = GetNextSymbol()) {
        switch (LastChar) {
            case '(':
            case '[':
            case '{':
                node.Token = LastChar;
                node.TheLine = currentLine;
                st.push(node);
                break;
            case ')':
            case ']':
            case '}':
                if (st.isEmpty()) {
                    Errors++;
                    cout << "in " << currentLine << " has an extra " << LastChar << endl;
                } else {
                    node = st.pop();
                    Match = node.Token;
                    if (!CheckMatch(Match, LastChar, node.TheLine, currentLine))
                        Errors++;
                }
                break;
        }

        while (!st.isEmpty()) {
            Errors++;
            node = st.pop();
            cout << "the " << node.TheLine << " line's symbol" << node.Token << "mismatches" << endl;
        }

        return Errors;
    }
}

bool balance::CheckMatch(char Symbol1, char Symbol2, int Line1, int Line2) {
    if (Symbol1 == '(' && Symbol2 != ')' || Symbol1 == '[' && Symbol2!=']' || Symbol1 == '{' && Symbol2 != '}') {
        cout << "find the " << Line2 << " symbol " << Symbol2 << " mismatches with the " << Line1 << " symbol " << Symbol1 << endl;
        return false;
    } else
        return true;
}

char balance::GetNextSymbol() {
    char ch;

    while (ch = NextChar()) {
        if (ch == '/') {
            ch = NextChar();
            if (ch == '*')
                SkipComment(SlashStar);
            else {
                if (ch == '/')
                    SkipComment(SlashSlash);
                else
                    PutBackChar(ch);
            }
        } else {
            if (ch == '\'' || ch == '"')
                SkipQuote(ch);
            else {
                if (ch == '{' || ch == '[' || ch == '(' || ch == ')' || ch == ']' || ch == '}')
                    return ch;
            }
        }
    }
    return NULL;
}

char balance::NextChar() {
    char ch;

    if ((ch = fin.get()) == EOF)
        return NULL;
    if (ch == '\n')
        currentLine++;
    return ch;
}

void balance::PutBackChar(char ch) {
    fin.putback(ch);
    if (ch == '\n')
        currentLine--;
}

void balance::SkipQuote(char type) {
    char ch;

    while ((ch = NextChar())) {
        if (ch == type)
            return;
        else {
            if (ch == '\n') {
                Errors++;
                cout << "missing closing quote at line " << currentLine << endl;
                return;
            } else {
                if (ch == '\\')
                    ch = NextChar();
            }
        }
    }
}

void balance::SkipComment(enum CommentType type) {
    char ch, flag;

    if (type == SlashSlash) {
        while ((ch = NextChar()) && (ch != '\n'));
        return;
    }

    flag = ' ';
    while ((ch = NextChar()) != NULL) {
        if (flag == '*' && ch == '/')
            return;
        flag = ch;
    }
    Errors++;
    cout << "Comment is unterminated!" << endl;
}