#include<stdio.h>
struct Stack
{
	int arr[5];
	int tos;	
};

void push (struct Stack*, int);
int pop (struct Stack*);

main()
{
	struct Stack S;
	S.tos = -1;
	int i, x;
	for(i = 1; i <= 5; i++)
	{
		printf("Enter value for push = ");
		scanf("%d", &x);
		push(&S, x);
		printf("Element %d pushed\n", x);
	}
	for(i = 1; i <= 5; i++)
	{
		x = pop(&S);
		if(x != 0)
			printf("Popped %d\n", x);
	}
	return 0;
}

void push(struct Stack *p, int x)
{
	if(p ->tos == 4)
	{
		printf("Stackoverflow\n");
		return;
	}
	/*
	p->tos = p->tos + 1;
	p->arr[p->tos] = x;  */
	p->arr[++p->tos] = x;
}
int pop(struct Stack *p)
{
	if(p->tos == -1)
	{
		printf("Underflow condition");
		return 0;
	}
	return (p->arr[p->tos--]);
}




/*
Function of push
1.  check for overflow condition
2. increase tos by 1
3. push element
4. return

Function of pop
1. check for underflow condition
2. pop element
3. decrease tos by 1
4. return

*/
