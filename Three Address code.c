
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char in[30];
int k = 1;

void printOperand(int i)
{
    for (int j = i-1; j <= i+1; j++)
    {
        if (j == i)
            printf("%c", in[j]);
        else if (isdigit(in[j]))
            printf("t%c", in[j]);
        else
            printf("%c", in[j]);
    }
}

void process(char op)
{
    for (int i = 0; in[i] != '\0'; i++)
    {
        if (in[i] == op)
        {
            printf("t%d=", k);

            printOperand(i);

            printf("\n");

            in[i-1] = '0' + k;

            for (int j = i; in[j] != '\0'; j++)
                in[j] = in[j+2];

            k++;
        }
    }
}

int main()
{
    printf("Enter the expression:\n");
    scanf("%29s", in);
    char res=in[0];

    printf("%s\n", in);

    process('/');
    process('*');
    process('+');
    process('-');

    printf("%c=t%d\n", res, k-1);

    return 0;
}
