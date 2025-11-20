#include<stdio.h>
#include<string.h>

void encodeMessage(char message[]){
	int length = strlen(message);
	
	int start = 0;
	int end = length - 1;
	
	while (start < end){
		char temp = message[start];
		message[start] = message[end];
		message[end] = temp;
		start++;
		end--;
	}
	printf("the reversed string is: %s\n" , message);
	
	for (int i = 0 ; i < length ; i++){
		message[i] = message[i] ^ 18;
	}
	
	printf("the encoded message is: %s\n" , message);	
}

void decodeMessage(char message[]){
	int length = strlen(message);
	
	for (int i = 0 ; i < length ; i++){
		message[i] = message[i] ^ 18;
	}
	
	int start = 0;
	int end = length - 1;
	while (start < end){
		char temp = message[start];
		message[start] = message[end];
		message[end] = temp;
		start++;
		end--;
	}
	
	printf("the decoded string is: %s\n" , message);
}

main(){
	int input;
	char message[1000];
	printf("enter your choice\n1 - encode\n2 - decode\n3 - exit \n");
	scanf("%d" , &input);
	while (input >= 1 && input <= 3){
		if (input == 1){
			printf("Encoding begins\n");
			printf("enter message: \n");
            scanf("%s" , &message);
                
                
            int len = strlen(message);
            if (len > 0 && message[len - 1] == '\n') {
                    message[len - 1] = '\0';
            }
                
            encodeMessage(message);
            printf("enter your choice\n1 - encode\n2 - decode\n3 - exit \n");
			scanf("%d" , &input);
		}
		
		else if (input == 2){
			printf("decoding begins\n");
			printf("Enter message to decode: ");
            scanf("%s" , &message);
                
                
            int len = strlen(message);
            if (len > 0 && message[len - 1] == '\n') {
                    message[len - 1] = '\0';
            }
                
            decodeMessage(message);
			printf("enter your choice\n1 - encode\n2 - decode\n3 - exit \n");
			scanf("%d" , &input);
		}
		
		else if (input == 3){
			printf("system exit\n");
			break;
		}
	}
}