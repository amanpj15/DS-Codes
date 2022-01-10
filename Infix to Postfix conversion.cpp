/*
EXAMPLE TO UNDERSTAND

A*B/C*E$F-G+H
A*B/C*EF$-G+H
AB* /C* EF$ -G+H
AB*C/ * EF$ -G+H
AB*C/EF$* -G+H
AB*C/EF$*G- +H
AB*C/EF$*G-H+

*/
#include<stdio.h>

struct Stack
{
	char arr[10];
	int tos;
};

void push(struct Stack*, char);
char pop(struct Stack*);
int isoprnd(char);
int precedence(char, char);
int isempty(struct Stack);
void convert(char[], char[]);

main()
{
	char infix[20], postfix[20];
	printf("Enter a valid Expression : ");
	scanf("%s", infix);
	convert(infix, postfix);
	printf("\nInfix is %s", infix);
	printf("\nPostsfix is %s", postfix);
}

void convert(char infix[20], char postfix[20])
{
	struct Stack S;
	int i, j = 0;
	char ch ;
	int result;
	S.tos = -1;
	for(i = 0; infix[i] != '\0'; i++)
	{
		ch = infix[i];
		if(isoprnd(ch) == 1)
		{
			postfix[j] = ch;
			j++;
		}
		else
		{
			while(isempty(S) == 0)
			{
				result = precedence(ch, S.arr[S.tos]);
				if(result == 1)
					break; // goes to push function call
				postfix[j] = pop(&S);
				j++;
			}
			push(&S, ch);
		}
	}
	
	while(isempty(S) == 0)
	{
		postfix[j] = pop(&S);
		j++;
	}
	postfix[j] = '\0';
}

int precedence(char op1, char op2)
{
	if(op2 == '$')
		return 0;
	else if(op1 == '$')
		return 1;
	else if(op2 == '*' || op2 == '/' || op2 == '%')
		return 0;
	else if(op1 == '*' || op1 == '/' || op1 == '%')
		return 1;
	else if(op2 == '+' || op2 == '-')
		return 0;
	else
		return 1;
}

void push(struct Stack *p, char ch)
{
	if(p->tos == 9)
	{
		printf("Stack Overflow");
		return;
	}
	p->tos = p->tos + 1;
	p->arr[p->tos] = ch;
}


char pop(struct Stack *p)
{
	char ch;
	if(p->tos == -1)
	{
		printf("Stack UnderFlow");
		return 0;
	}	
	ch = p->arr[p->tos];
	p->tos = p->tos - 1;
	return ch;
}

int isempty(struct Stack S)
{
	if(S.tos == -1)
		return 1;
	else
		return 0;
}

int isoprnd(char ch)
{
	if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
		return 1;
	else
		return 0;
}
