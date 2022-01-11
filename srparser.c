#include<stdio.h>
#include<string.h>
char input[20], stack[20];
int tos, cur_pos;
void srparser()
{
    int i=0, k=0;
    char temp[3];
    stack[0] = '$';
    tos = 0;
    stack[tos+1] = '\0';
    while(i<strlen(input))
    {
        cur_pos = i;
        k=0;
        printf("%s\t\t",stack);
        for(int j=cur_pos; j<strlen(input); j++)
        {
            printf("%c", input[j]);
        }
        if(stack[tos] == 'a')
        {
            printf("\t\tReduce E->a");
            stack[tos] = 'E';
        }
        else if(stack[tos] == 'E' && tos>1)
        {
            for(int j=tos-2; j<=tos; j++)
            {
                temp[k] = stack[j];
                k++;
            }
            temp[k] = '\0';
            if(strcmp(temp, "E+E") == 0)
            {
                printf("\t\tReduce E->E+E");
                stack[tos-2] = 'E';
                tos -= 2;
            }
            else if(strcmp(temp, "E*E") == 0)
            {
                printf("\t\tReduce E->E*E");
                stack[tos-2] = 'E';
                tos -= 2;
            }
        }
        else if(tos == 1 && stack[tos] == 'E' && input[cur_pos] == '$')
        {
            //printf("\t\t%c", stack[1]);
            printf("\t\tAccepted");
            exit(0);
        }
        else
        {
            printf("\t\tShift %c", input[cur_pos]);
            tos++;
            stack[tos] = input[cur_pos];
            i++;
        }
        stack[tos+1] = '\0';
        printf("\n");
    }
}
int main()
{
    printf("The productions are:\nE->E+E\nE->E*E\nE->a\n");
    printf("Enter the input string: ");
    gets(input);
    input[strlen(input)] = '$';
    printf("\nStack\t\tInput\t\tAction\n");
    srparser();
    printf("Rejected");
    return 0;
}