#include<stdio.h>

int max = 5;

int push(int stack[] , int top){
	int data;
	if (top == (max - 1)){
		printf("OVERFLOW. STACK IS FULL\n");
		return 0;
	}
	else {
		printf("Enter data you want to enter: \n");
		scanf("%d" , &data);
		top++;
		stack[top] = data;
		printf("Data entered\n");
		return 1; 
	}
}

int pop(int stack[] , int top){
	if (top == -1){
		printf("UNDERFLOW. STACK IS EMPTY\n");
		return 0;
	}
	else {
		int value = stack[top];
		top--;
		printf("removed data: %d\n" , value);
		return 1;
	}
}

void peek(int stack[] , int top){
	if (top == -1){
		printf("STACK IS EMPTY\n");
	}
	else {
		printf("The value at the top is: %d\n" , stack[top]);
	}
}

void display(int stack[] , int top){
	if (top == -1){
		printf("STACK IS EMPTY\n");
	}
	else {
		printf("=== STACK ===\n");
		for (int i = 0 ; i < top + 1 ; i++){
			printf("%d\n" , stack[i]);
		}
	}
}

int main(){
	int stack[5];
	int top = -1;
	int input;
	
	printf("STACK MENU\n");
	printf("1- PUSH\n");
	printf("2- POP\n");
	printf("3- PEEK\n");
	printf("4- DISPLAY\n");
	printf("5- EXIT\n");
	scanf("%d" , &input);
	
	while (input >= 1 && input <=5){
		switch (input){
			
			case (1):{
				int value = push(stack , top);
				if (value == 1){
					top++;
				}
				printf("STACK MENU\n");
				printf("1- PUSH\n");
				printf("2- POP\n");
				printf("3- PEEK\n");
				printf("4- DISPLAY\n");
				printf("5- EXIT\n");
				scanf("%d" , &input);
				break;
			}
				
			case (2):{
				int value = pop(stack , top);
				if (value == 1){
					top--;
				}
				printf("STACK MENU\n");
				printf("1- PUSH\n");
				printf("2- POP\n");
				printf("3- PEEK\n");
				printf("4- DISPLAY\n");
				printf("5- EXIT\n");
				scanf("%d" , &input);
				break;
			}
			
			case (3):
				peek(stack , top);
				printf("STACK MENU\n");
				printf("1- PUSH\n");
				printf("2- POP\n");
				printf("3- PEEK\n");
				printf("4- DISPLAY\n");
				printf("5- EXIT\n");
				scanf("%d" , &input);
				break;
				
			case (4):
				display(stack , top);
				printf("STACK MENU ===\n");
				printf("1- PUSH\n");
				printf("2- POP\n");
				printf("3- PEEK\n");
				printf("4- DISPLAY\n");
				printf("5- EXIT\n");
				scanf("%d" , &input);
				break;
			
			case (5):
				printf("system exit goodbye\n");
				break;
			
			default :
				printf("inalid inout enter again.\n");
				printf("STACK MENU\n");
				printf("1- PUSH\n");
				printf("2- POP\n");
				printf("3- PEEK\n");
				printf("4- DISPLAY\n");
				printf("5- EXIT\n");
				scanf("%d" , &input);
				break;
		}
	}
}

