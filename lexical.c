#include<stdio.h>
#include<string.h>

void main()
{
    FILE *file;
    char words[100][20], line[100];
    char keywords[][20] = {"int", "return"};
    char identifiers[][20] = {"main", "a", "b", "c"};
    char special_char[] = {'(', ')', '{', ',', ';', '=', '+', '}'};
    char cur_word[20], cur_identif[20];
    int count=0, k=0, row=0;
    file = fopen("program.txt", "r");
    while(!feof(file))
    {
        fgets(line, 100, file);
        count++;
        for(int i=0; i<strlen(line); i++)
        {
            if(line[i] != ' ' && line[i] != '\n')
            {
                words[row][k] = line[i];
                k++;
            }
            else
            {
                words[row][k] = '\0';
                row++;
                k = 0;
            }
        }
    }
    printf("The numbers in the program are: ");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<strlen(words[i]); j++)
        {
            if(words[i][j] >= '0' && words[i][j] <= '9')
            {
                printf("%c", words[i][j]);
            }
            else if(words[i][j] == ',')
            {
                printf(" ");
            }
        }
    }
    printf("\nThe keywords and identifiers are:\n");
    for(int i=0; i<row; i++)
    {
        strcpy(cur_word, words[i]);
        for(int j=0; j<strlen(keywords); j++)
        {
            if(strcmp(cur_word, keywords[j]) == 0 && strcmp(cur_word, "") != 0)
            {
                printf("%s is a keyword\n", cur_word);
                break;
            }
        }
        for(int j=0; j<strlen(identifiers); j++)
        {
            if(strcmp(cur_word, identifiers[j]) == 0)
            {
                printf("%s is an identifier\n", cur_word);
                break;
            }
        }
    }
    printf("The special characters are: ");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<strlen(words[i]); j++)
        {
            for(int k=0; k<sizeof(special_char); k++)
            {
                if(words[i][j] == special_char[k])
                {
                    printf("%c ", words[i][j]);
                    break;
                }
            }
        }
    }
    printf("\nTotal number of lines: %d", count);
}