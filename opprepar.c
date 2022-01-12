#include<stdio.h>
#include<string.h>

char input[50];
int i=0;
char lasthandle[6], stack[50], handles[][5]={"E*E","E+E","i"};
int top=0;

int precedence(char c)
{
    switch(c)
    {
        case '+':return 1;
        case '*':return 2;
        case 'i':return 3;
        case '$':return 0;
    }
}

int shift()
{
    stack[++top] = input[i++];
    stack[top+1] = '\0';
}

int reduce()
{
    int i, len, found, t;
    for(i=0; i<3; i++)//selecting handles
    {
        len = strlen(handles[i]);
        if(stack[top]==handles[i][0] && top+1>=len)
        {
            found = 1;
            for(t=0; t<len; t++)
            {
                if(stack[top-t] != handles[i][t])
                {
                    found=0;
                    break;
                }
            }
            if(found == 1)
            {
                stack[top-t+1] = 'E';
                top = top-t+1;
                strcpy(lasthandle, handles[i]);
                stack[top+1]='\0';
                return 1;//successful reduction
            }
        }
    }
    return 0;
}

void dispinput()
{
    for(int j=i; j<strlen(input); j++)
        printf("%c", input[j]);
}

int main()
{
    int j;
    printf("\nEnter the string\n");
    scanf("%s", input);
    strcat(input, "$");
    strcpy(stack, "$");
    printf("\nSTACK\t\tINPUT\t\tACTION");
    while(i<strlen(input))
    {
        shift();
        printf("\n%s\t\t", stack);
        dispinput();
        printf("\t\tShift");
        if(precedence(stack[top]) > precedence(input[i]))
        {
            while(reduce())
            {
                printf("\n%s\t\t", stack);
                dispinput();
                printf("\t\tReduced: E->%s",lasthandle);
            }
        }
    }

    if(strcmp(stack, "$E$") == 0)
        printf("\nAccepted");
    else
        printf("\nNot Accepted");
}