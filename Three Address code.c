#include <stdio.h>
#include <string.h>

char in[30][10];
int n = 0, k = 1;

void process(char op)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(in[i], (char[]){op, '\0'}) == 0)
        {
            char temp[10], arg1[10], arg2[10];

            strcpy(arg1, in[i-1]);
            strcpy(arg2, in[i+1]);

            sprintf(temp, "t%d", k);

            printf("%s=%s%c%s\n", temp, arg1, op, arg2);

            strcpy(in[i-1], temp);

            for (int j = i; j < n-2; j++)
                strcpy(in[j], in[j+2]);

            n -= 2;
            k++;
            i--;
        }
    }
}

int main()
{
    char lhs[10];
    char exp[100];
    int j;

    printf("Enter the expression:\n");
    scanf("%99s", exp);
    strcpy(lhs, exp);
    lhs[1] = '\0';

    // Tokenize expression
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' ||
            exp[i] == '*' || exp[i] == '/')
        {
            in[n][0] = exp[i];
            in[n][1] = '\0';
            n++;
        }
        else
        {
            j = 0;

            while (exp[i] != '\0' &&
                   exp[i] != '+' && exp[i] != '-' &&
                   exp[i] != '*' && exp[i] != '/')
            {
                in[n][j++] = exp[i++];
            }

            in[n][j] = '\0';
            n++;
            i--;
        }
    }

    printf("\nThree Address Code:\n");

    process('/');
    process('*');
    process('+');
    process('-');

    printf("%s=%s\n", lhs, in[0]);

    return 0;
}
