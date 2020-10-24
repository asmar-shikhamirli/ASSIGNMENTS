#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

#define STACK_CAPACITY 100 

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct Stack* createStack() 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = STACK_CAPACITY; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

// deallocates the dynamic memory to prevent memory leak
void deallocStack(struct Stack* stack) 
{ 
    free(stack->array);
    free(stack);
    printf("deallocated\n"); 
} 

int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 

void resize(struct Stack* stack) 
{
    stack->capacity *= 2;
    stack->array = (int*)realloc(stack->array,stack->capacity * sizeof(int));
    printf("stack reallocated, new length: %d\n",stack->capacity);
} 

void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        resize(stack);
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
  
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 
  
bool isMatchingPair(char char1, char char2)
{
    if (char1 == '(' && char2 == ')')
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else if (char1 == '[' && char2 == ']')
        return 1;
    else
        return 0;
}
  
bool checkBalance(char exp[])
{
	int i = 0;

	struct Stack* stack = NULL;

	while (exp[i])
	{
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(stack, exp[i]);

        	if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
		{
			if (stack == NULL)
                		return 0;

           	 else if (!isMatchingPair(pop(stack), exp[i]))
                	return 0;
       		}
      		i++;
    	}


	if (stack == NULL) 
        	return 1; //balanced 
    	else	
        	return 0; //not balanced 
} 	

int main() 
{
	struct Stack* stack = createStack(); 

	char exp[1000];
       
	scanf("%s", exp);

	if (checkBalance(exp))
        	printf("Balanced \n");
	else
		printf("Not Balanced \n");

	deallocStack(stack);
	return 0;
     
} 
