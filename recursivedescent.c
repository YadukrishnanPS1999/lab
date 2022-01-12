#include<stdio.h>
#include<string.h>

char input[100];
int pos=0;

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if(input[pos] == '+')
    {
        pos++;
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if(input[pos] == '*')
    {
        pos++;
        F();
        Tprime();
    }
}

void F()
{
    if(input[pos] == '(')
    {
        pos++;
        E();
        if(input[pos] == ')')
        {
            pos++;
        }
    }
    else if(input[pos] == 'a')
    {
        pos++;
    }
}

void main()
{
    printf("Enter the input string: ");
    scanf("%s", input);
    input[strlen(input)] = '$';
    E();
    if(input[pos] == '$')
    {
        printf("Accepted");
    } 
    else
    {
        printf("Rejected");
    }
}