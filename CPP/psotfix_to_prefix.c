#include "stdio.h"
#include "conio.h"

struct St
{
    char *arr[20];
    int top;
};

int isEmpty(struct St *st)
{
    return st->top;
}

int isFull(struct St *st)
{
    if (st->top == 20)
        return 1;

    return 0;
}
void push(struct St *st, char *x)
{
    if (isFull(st))
        printf("Stack is FULL\n");

    else
        st->arr[++st->top] = x;
}

char *pop(struct St *st)
{
    if (isEmpty(st))
        printf("No element to pop\n");
    else
    {
        char *temp = st->arr[st->top--];
        return temp;
    }
}

struct St *constructer()
{
    struct St *s = (struct St *)malloc(sizeof(struct St));
    s->top = -1;
    return s;
}

char *postfixToInfix(char *exp)
{
    struct St *s = constructer();
    for (int i = 0; i < sizeof(exp) - 1; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            char * op2 = pop(s);
            char * op1 = pop(s);
            
        }
        else{
            push(s,exp[i]);
        }
    }
}

int main()
{

    return 0;
}