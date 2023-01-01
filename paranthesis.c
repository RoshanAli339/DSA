#include <stdio.h>

char stk[20], top = -1;

void push(char ch)
{
	if (top == 19)
		return;
	stk[++top] = ch;
}

char peek()
{
	if (top == -1)
		return 1;
	return stk[top];
}

char pop()
{
	if (top == -1)
		return 1;
	return stk[top--];
}

int isValid(char *expr)
{
	int a[126] = {0};
	a['('] = 1;
	a['['] = 1;
	a['{'] = 1;
	if (a[expr[0]] == 0)
		return 0;
	for (int i = 0; expr[i] != '\0'; ++i)
	{
		if (a[expr[i]] == 1)
			push(expr[i]);
		else
		{
			switch (expr[i])
			{
				case ')':
					if (peek() == '(') pop();
					else return 0;
					break;
				case ']':
					if (peek() == '[') pop();
					else return 0;
					break;
				case '}':
					if (peek() == '{') pop();
					else return 0;
					break;
			}
		}
	}
	if (top != -1)
		return 0;
	return 1;
}

int main()
{
	char expr[20];
	printf("Enter an expression: ");
	scanf(" %[^\n]", expr);
	if(isValid(expr))
		printf("Valid expression\n");
	else
		printf("Invalid expression\n");
}
