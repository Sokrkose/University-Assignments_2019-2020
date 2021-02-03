#include <stdio.h>
#include <stdlib.h>

int isPowerOf2(int a){
     
	if(a == 0){
		return 0;
	}

  	while (a != 1) 
  	{ 
      	if (a%2 != 0){ 
        	return 0;  //it is not power of 2
      	} 
      	a = a/2; 
  	} 

  	return 1; //it is power of 2

}

/* ==================== (i) VECTOR: REALLOC AT EACH UPDATE */

struct Stack {
  int top;                      /* pointer to the top of the stack */
  int* array;                   /* stack elements */
};

struct Stack* createStack() 
{ 
	struct Stack* stack;

	stack = (struct Stack* ) malloc(sizeof(struct Stack));
    stack->array = (int* ) malloc(0);
	stack->top = -1;

    return stack;

}

int isEmpty(struct Stack* stack){

	if(stack->top == -1){
		return 1;
	}

	return 0;

}

void push(struct Stack* stack, int item){

	stack->array = (int* ) realloc(stack->array, (stack->top + 2)*sizeof(int ));
	stack->top++;
	stack->array[stack->top] = item;


}

int pop(struct Stack* stack){
	
	int isEmptyFlag = isEmpty(stack);
	int output = stack->array[stack->top];

	if(isEmptyFlag == 1){
		exit(1);
	}else{
		stack->array = (int* ) realloc(stack->array, (stack->top)*sizeof(int ));
		stack->top--;
	}

	return output;

}


/* ==================== (ii) VECTOR: REALLOC AT POWERS OF 2 */

struct StackFast {
  int top;                      /* pointer to the top of the stack */
  int* array;                   /* stack elements */
};

struct StackFast* createStackFast() 
{

    struct StackFast *stack;
    stack = (struct StackFast* ) malloc(sizeof(struct StackFast));
    stack->array = (int* ) malloc(0);
    stack->top = -1;
    
    return stack;

}

int isEmptyFast(struct StackFast* stack){

	if(stack->top == -1){
		return 1;
	}

	return 0;

}

void pushFast(struct StackFast* stack, int item){

	int isPowerOf2Flag = isPowerOf2(stack->top + 1);

	if(isPowerOf2Flag == 1){
        stack->array = (int* ) realloc(stack->array, (stack->top + 1)*2*sizeof(int) );
    }

    stack->top++;
    stack->array[stack->top] = item;

}

int popFast(struct StackFast* stack){

	int isEmptyFlag = isEmptyFast(stack);
	int output = stack->array[stack->top];

	if(isEmptyFlag == 1){
		exit(1);
	}else{
		int isPowerOf2Flag = isPowerOf2(stack->top);
		stack->top--;

		if(isPowerOf2Flag == 1){
        	stack->array = (int* ) realloc(stack->array, (stack->top - 1)*sizeof(int) );
    	}
	}

	return output;

}
