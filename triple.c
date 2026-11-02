
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char exxp[20];
int count = 0;
int i, j;

void printOperand(int i)
{
    if (isdigit((unsigned char)exxp[i-1]))
        printf("\t(%c)", exxp[i-1]);
    else
        printf("\t%c", exxp[i-1]);
    printf("\t%c\t", exxp[i]);
    if (isdigit((unsigned char)exxp[i+1]))
        printf("(%c)", exxp[i+1]);
    else
        printf("%c", exxp[i+1]);
}

void process(char op)
{
    for (int i = 0; exxp[i] != '\0'; i++)
    {
        if (exxp[i] == op)
        {
            printf("(%d)\t", count);
            printOperand(i);
            printf("\n");
            exxp[i-1] = '0' + count;
            int j;
            for (j = i; exxp[j+2] != '\0'; j++)
                exxp[j] = exxp[j+2];
            exxp[j] = '\0';
            count++;
        }
    }
}
int main()
{
    printf("Enter the expression:\n");
    scanf("%19s", exxp);
    char res=exxp[0];
    printf("\nindex\tOP\tARG1\tARG2\n");
    process('/');
    process('*');
    process('+');
    process('-');
    printf("(%d)\t\t=\t%c ", count, res);
    if (isdigit(exxp[0]))
        printf("\t(%c)\n", exxp[0]);
    else
        printf("\t%c\n", exxp[0]);
    return 0;
}
