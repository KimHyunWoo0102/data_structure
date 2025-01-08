#include "PostCalculdator.h"
#include "ListBaseStack.h"

#include<string.h>
#include<ctype.h>

int calcul(char d1, char d2, char op) {
    switch (op)
    {
    case '+':
        return d1 + d2;
    case'-':
        return d1 - d2;
    case '*':
        return d1 * d2;
    case '/':
        return d1 / d2;
    }

    return -1;
}

int EvalPRNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    char tok, op1, op2;

    StackInit(&stack);

    for (int i = 0; i < expLen; i++) {
        tok = exp[i];

        if (isdigit(tok)) {
            SPush(&stack, tok-'0');
        }
        else {
            op2 = SPop(&stack);
            op1 = SPop(&stack);

            SPush(&stack, calcul(op1, op2, tok));
        }
    }
    return SPop(&stack);
}
