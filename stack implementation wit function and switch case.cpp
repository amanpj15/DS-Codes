#include<stdio.h>
#include<process.h>
struct Stack
{
	int arr[5];
	int tos;	
};

void push(struct Stack *, int);
int pop(struct Stack*);
int peek(struct Stack*);
void display(struct Stack*);

main()
{
	int ich;
	struct Stack S;
	int x, i;
	S.tos = -1;
		printf("What you want\n");
		printf("1. Push Element\n");
		printf("2. Pop Element\n");
		printf("3. Peek Element\n");
		printf("4. Display Elements\n");
		printf("3. Exit\n");
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d", &ich);
	
	
		switch(ich)
		{
			case 1 :
					printf("Enter value for push = ");
					scanf("%d", &x);
					
					push(&S, x) ;
					break;
			case 2:
						x = pop(&S);
					if(x != 0)
						printf("\nPoped %d\n\n", x);
		
			break;
			case 3: 
					if (x != 0)
						printf("Top Element = %d",peek(&S));
			break;
			case 4: 
				display(&S);
			break;
			
			default:printf("\nInvalid input\n");
		}
				
	}while(ich != 3);
}
void push(struct Stack *P, int x)
{
	if(P->tos == 4)
	{
		printf("Stackoverflow\n");
		return;
	}
	P->tos = P->tos + 1;
	P->arr[P->tos] = x;
	printf("Pushed %d\n", x);
	
}
int pop(struct Stack *P)
{
	int x;
	if(P->tos == -1)
	{
		printf("\nStackunderflow\n");
		return 0;
	}
	x = P->arr[P->tos];
	P->tos = P->tos - 1;
	return x;
}

int peek(struct Stack *p)
{
	if(p->tos == -1)
	{
		printf("Stack is empty");
		return 0;
	}
	return (p->arr[p->tos]);
}
void display(struct Stack *p)
{
	int i;
	for(i = p->tos; i >= 0; i--)
		printf("Element %d = %d\n", i+1, p->arr[p->tos--]);
}
