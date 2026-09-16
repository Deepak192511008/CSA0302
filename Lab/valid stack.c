#include <stdio.h>

int main()
{
    char str[100], stack[100];
    int top = -1;
    int i, valid = 1;

    printf("Enter string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            stack[++top] = str[i];
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (top == -1)
            {
                valid = 0;
                break;
            }

            if ((str[i] == ')' && stack[top] != '(') ||
                (str[i] == ']' && stack[top] != '[') ||
                (str[i] == '}' && stack[top] != '{'))
            {
                valid = 0;
                break;
            }

            top--;
        }
    }

    if (top != -1)
        valid = 0;

    if (valid)
        printf("Valid String");
    else
        printf("Invalid String");

    return 0;
}
