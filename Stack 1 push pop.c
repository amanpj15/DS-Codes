#include<stdio.h>
struct Stack
{
	int arr[5];
	int tos;
};

main()
{
	struct Stack S;
	int i, x;
	S.tos = -1;
	for(i = 0; i < 5 ; i++)
	{
		printf("Enter number %d = ", i + 1);
		scanf("%d", &x);
		S.tos = S.tos + 1;
		S.arr[S.tos] = x;
		printf("Push %d\n", x);
	}
	for(i = 0; i < 5; i++)
	{
		x =	S.arr[S.tos];
		S.tos = S.tos - 1;
		printf("Popped element = %d\n", x);
	}
}
