#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int stk[10], top = -1;

void push(int v)
{
	if (top == 9)
		return;
	stk[++top] = v;
}

int pop()
{
	if (top == -1)
		return 1;
	return stk[top--];
}

int peek()
{
	if (top == -1)
		return 1;
	return stk[top];
}

int evalPostfix(char *postfix)
{
	char *num = NULL, index;
	for (int i = 0; postfix[i] != '\0'; ++i)
	{
		if (num == NULL)
		{
			index = -1;
			num = (char*)malloc(4*sizeof(int));
		}
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			num[++index] = postfix[i];
		}
		else if (postfix[i] == ' ')
		{
			if (num != NULL && index != -1)
				push(atoi(num));
			free(num);
			num = NULL;
		}
		else
		{
			int a, b, c;
			switch (postfix[i])
			{
				case '+': c = pop() + pop(); break;
				case '-': 
					  a = pop();
					  b = pop();
					  c = b - a;
					  break;
				case '*': c = pop() * pop(); break;
				case '/':
					  a = pop();
					  b = pop();
					  c = b / a;
					  break;
				case '%':
					  a = pop();
					  b = pop();
					  c = b % a;
					  break;
				case '^':
					  a = pop();
					  b = pop();
					  c = pow(b,a);
					  break;
				default:
					  printf("Invalid expression!!\n");
					  return -1;
			}
			push(c);
		}
	}
	if (top > 0)
	{
		printf("Invalid expression!!\n");
		return -1;
	}
	return peek();
}

int main()
{
	char postfix[20];
	printf("Enter a postfix expression: ");
	scanf(" %[^\n]", postfix);
	int val = evalPostfix(postfix);
	printf("Value= %d\n", val);
}


