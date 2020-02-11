#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DATA
{
	int x;
}data;

typedef struct NODE
{
	struct DATA data;
	struct NODE *next;
}node;

typedef struct STACK
{
	struct NODE* top;
}stack;

void initstack(stack* stack);
void pushstack(stack* stack, data data);
data popstack(stack* stack);
bool isempty(stack* stack);
void printstack(stack* stack);

int main()
{
	char cmd[80];
	stack s1;
	data data;

	initstack(&s1);

	while (1)
	{
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0)
		{
			scanf("%d", &data.x);
			pushstack(&s1, data);
		}
		if (strcmp(cmd, "pop") == 0)
		{
			printf("pop할 숫자는 %d입니다.\n", popstack(&s1)); // data형이 이걸로 변환될 지는 모르겠으
		}
		if (strcmp(cmd, "print") == 0)
		{
			printstack(&s1);
		}
		if (strcmp(cmd, "esc") == 0)
		{
			break;
		}
	}
	return 0;
}

void initstack(stack* stack)
{
	stack->top = NULL;
}
void pushstack(stack* stack, data data)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = stack->top;

	stack->top = newnode;
}
data popstack(stack* stack)
{
	if (stack->top == NULL)
	{
		printf("STACK IS UNDERFLOW!\n");
		exit(1);
	}
	else
	{
		node* temp;
		data data;

		temp = stack->top;
		data = stack->top->data;
		stack->top = stack->top->next;

		free(temp);
		return data;
	}
}
bool isempty(stack* stack)
{
	if (stack->top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void printstack(stack* stack)
{
	if (isempty(stack))
	{
		printf("STACK IS UNDERFLOW!\n");
		exit(1);
	}
	else
	{
		node* temp;
		temp = stack->top;
		while (1)
		{
			printf("-> %d\n", temp->data.x);
			if (temp->next == NULL)
			{
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}