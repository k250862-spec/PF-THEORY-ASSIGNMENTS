#include<stdio.h>
#include<string.h>
int max = 100;
int ISBNS[100];
char tittles[100][50];
float prices[100];
int quantities[100];
int count = 0;
int choice;
int numbofbooks = 0;
	

void addbook(){
				if (numbofbooks >= max){
					printf("Library is full. Book can not be added\n");
					printf("LIBERTY BOOKSTORE\n");
					printf("ENTER YOUR CHOICE FROM THE MENU\n");
					printf("1 - Add new book\n");
					printf("2- Process a sale\n");
					printf("3- Generate Low stock report\n");
					printf("4- Exit\n");
					scanf("%d" , &choice);
				}
				else{
					int userISBN;
					printf("enter book isbn: \n");
					scanf("%d" , &userISBN);
					int found = 0;	
					for (int i = 0 ; i <= numbofbooks ; i++){
						if (ISBNS[i] == userISBN){
							found = 1;
						}
					}
					if (found == 1){
						printf("ISBN %d already exits. Book can not be added.\n" , userISBN);
					}
					else if (found == 0){
						ISBNS[numbofbooks] = userISBN;
						printf("ISBN entered\n");
						
						printf("enter book tittle: \n");
						fgets(tittles[numbofbooks] , 100 , stdin);
						scanf(" %[^\n]", &tittles[numbofbooks]);
						
						printf("enter book price: \n");
						scanf("%f" , &prices[numbofbooks]);
						
						printf("enter quantity: \n");
						scanf("%d" , &quantities[numbofbooks]);
						
						numbofbooks++;
						
						printf("book added\n");
						printf("LIBERTY BOOKSTORE\n");
						printf("ENTER YOUR CHOICE FROM THE MENU\n");
						printf("1 - Add new book\n");
						printf("2- Process a sale\n");
						printf("3- Generate Low stock report\n");
						printf("4- Exit\n");
						scanf("%d" , &choice);

					}
					}
					
		}

void sale(){
			printf("%d books in library\n" , numbofbooks);
			if (numbofbooks == 0){
					printf("No books in Library.\n");
					printf("LIBERTY BOOKSTORE\n");
					printf("ENTER YOUR YOUR CHOICE\n");
					printf("1 - Add new book\n");
					printf("2- Process a sale\n");
					printf("3- Generate Low stock report\n");
					printf("4- Exit\n");
					scanf("%d" , &choice);
				}
				
			if (numbofbooks != 0){
					int newISBN , copies;
					printf("enter the ISBN of the book: \n");
					scanf("%d" , &newISBN);		
				
					int bookindex = -1;
					for (int i = 0 ; i < numbofbooks ; i++){
						if (ISBNS[i] == newISBN){
						bookindex = i;
						}
					}
				
			if (bookindex == -1){
						printf("Book not available in library.\n");
						printf("LIBERTY BOOKSTORE\n");
						printf("ENTER YOUR CHOICE\n");
						printf("1 - Add new book\n");
						printf("2- Process a sale\n");
						printf("3- Generate Low stock report\n");
						printf("4- Exit\n");
						scanf("%d" , &choice);
					}
			if (bookindex != -1){
						printf("enter the amount of copies: \n");
						scanf("%d" , &copies);
				
						if (copies > quantities[bookindex]){
							printf("%d copies are available.\n" , quantities[bookindex]);
							printf("LIBERTY BOOKSTORE\n");
							printf("ENTER YOUR CHOICE\n");
							printf("1 - Add new book\n");
							printf("2- Process a sale\n");
							printf("3- Generate Low stock report\n");
							printf("4- Exit\n");
							scanf("%d" , &choice);
						}
				
						quantities[bookindex] = quantities[bookindex] - copies;
						float cost;
						cost = cost + (prices[bookindex] * copies);
						printf("sale completed\n");
						printf("book ISBN: %d\n" , ISBNS[bookindex]);
						printf("book tittle: %s\n" , tittles[bookindex]);
						printf("number of copies: %d\n" , copies);
						printf("amount to pay: %0.2f\n" , cost);
						printf("LIBERTY BOOKSTORE\n");
						printf("ENTER YOUR CHOICE\n");
						printf("1 - Add new book\n");
						printf("2- Process a sale\n");
						printf("3- Generate Low stock report\n");
						printf("4- Exit\n");
						scanf("%d" , &choice);
					}
				}
	
}

void lowstockreport(){
			int lowcount = 0;
			if (numbofbooks == 0){
				printf("no books in library\n");
				printf("LIBERTY BOOKSTORE\n");
				printf("ENTER YOUR CHOICE\n");
				printf("1 - Add new book\n");
				printf("2- Process a sale\n");
				printf("3- Generate Low stock report\n");
				printf("4- Exit\n");
				scanf("%d" , &choice);
			}
			for (int i = 0 ; i < numbofbooks ; i++){
				if (quantities[i] < 5){
					lowcount ++;
					printf("Books with quantity less than 5: \n");
					printf("Tittle: %s\n" , tittles[i]);
					printf("ISBN: %d\n" , ISBNS[i]);
					printf("Price: %.2f\n" , prices[i]);
					printf("quantity: %d\n" , quantities[i]);
				}
			}
			printf("LIBERTY BOOKSTORE\n");
			printf("ENTER YOUR CHOICE\n");
			printf("1 - Add new book\n");
			printf("2- Process a sale\n");
			printf("3- Generate Low stock report\n");
			printf("4- Exit\n");
			scanf("%d" , &choice);
			
	
}

main(){
	
	printf("LIBERTY BOOKSTORE\n");
	printf("ENTER YOUR CHOICE FROM THE MENU\n");
	printf("1 - Add new book\n");
	printf("2- Process a sale\n");
	printf("3- Generate Low stock report\n");
	printf("4- Exit\n");
	scanf("%d" , &choice);
	while (choice >= 1&& choice <= 4){
		if (choice == 1){
				addbook();
				
			}
					
		else if (choice ==2){
				sale();
			}
			
				
		
		else if (choice == 3){
			lowstockreport();
		}
		
		if (choice == 4){
			
			printf("system exit.Goodbye\n");
			
			break;
		}
		
	}
}