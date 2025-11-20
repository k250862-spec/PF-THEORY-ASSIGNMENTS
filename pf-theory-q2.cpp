#include<stdio.h>
#include<string.h>

char name[100];
int CNIC;
int choice;
int productcode[4] = {001 , 002 , 003 , 004};
int quantity[4] = {50 , 10 , 20 , 8};
int priceperproduct[4] = {100 , 200 , 300 , 150};
int cart[4][3];
int cartindex = 0;
int bill = 0;
float amount = 0;
float newbill = 0;
char promocode[100];
char promocheck[100];
int discapplied = 0;


void customerinfo(){
			printf("enter your name: \n");
			scanf("%s" , &name);
			printf("enter your cnic number: \n");
			scanf("%d" , &CNIC);
			printf("   SUPERMARKET MANAGEMENNT SYSTEM   \n");
			printf("chose any one of the following options:\n");
			printf("1- input customer information\n");
			printf("2- display inventory\n");
			printf("3- add item to cart\n");
			printf("4- display total bill\n");
			printf("5- display invoice\n");
			printf("6- EXIT\n");
			scanf("%d" , &choice);
}

void inventory(){
			printf("   INVENTORY   \n");
			printf("\n");
			printf("PRODUCT CODE | QUANTITY | PRICE");
			printf("\n");
			for (int i = 0 ; i < 4 ; i++){
				printf("%d" "              %d" "         %d\n" ,productcode[i] , quantity[i] ,priceperproduct[i]);
			}
			printf("\n");
			printf("   SUPERMARKET MANAGEMENNT SYSTEM   \n");
			printf("chose any one of the following options:\n");
			printf("1- input customer information\n");
			printf("2- display inventory\n");
			printf("3- add item to cart\n");
			printf("4- display total bill\n");
			printf("5- display invoice\n");
			printf("6- EXIT\n");
			scanf("%d" , &choice);
	
}

void addtocart(){
			int usercode;
			int userquantity;
			int productindex;
			int stockcheck = 1;
			int found = 0;
			printf("    ADD ITEM TO CART   \n");
			printf("Enter product code: \n");
			scanf("%d" , &usercode);
			for (int i = 0 ; i < 4 ; i++){
				if (productcode[i] == usercode){
					productindex = i;
					found = 1;
				}
			}
			if (found == 1){
				printf("PRODUCT FOUND\n");
				printf("Enter quantity: ");
				printf("\n");
				scanf("%d" , &userquantity);
			}
			else if (found == 0){
				printf("PRODUCT NOT FOUND\n");
				printf("   SUPERMARKET MANAGEMENNT SYSTEM   \n");
				printf("chose any one of the following options:\n");
				printf("1- input customer information\n");
				printf("2- display inventory\n");
				printf("3- add item to cart\n");
				printf("4- display total bill\n");
				printf("5- display invoice\n");
				printf("6- EXIT\n");
				scanf("%d" , &choice);
			}
			
			if (found == 1 && userquantity > quantity[productindex]){
				printf("THIS MUCH STOCK IS NOT AVAILABLE\n");
				stockcheck = 0;
				printf("   SUPERMARKET MANAGEMENNT SYSTEM   \n");
				printf("chose any one of the following options:\n");
				printf("1- input customer information\n");
				printf("2- display inventory\n");
				printf("3- add item to cart\n");
				printf("4- display total bill\n");
				printf("5- display invoice\n");
				printf("6- EXIT\n");
				scanf("%d" , &choice);
			}
			
			if (stockcheck == 1 && found == 1){
				bill = priceperproduct[productindex] * userquantity;
				amount = amount + bill;
				cart[cartindex][0] = usercode;
				cart[cartindex][1] = userquantity;
				cart[cartindex][2] = bill;
				quantity[productindex] = quantity[productindex] - userquantity;
				cartindex++;
				printf("ITEM ADDED TO CART\n");
				printf("   SUPERMARKET MANAGEMENNT SYSTEM   \n");
				printf("chose any one of the following options:\n");
				printf("1- input customer information\n");
				printf("2- display inventory\n");
				printf("3- add item to cart\n");
				printf("4- display total bill\n");
				printf("5- display invoice\n");
				printf("6- EXIT\n");
				scanf("%d" , &choice);
			}
}

void displaybill(){
			printf("TOTAL BILL WITHOUT DISCOUNT: %.2f\n" , amount);
			printf("Do you have a promocode (yes or no): \n");
			scanf("%s" , &promocheck);
			if (strcmp(promocheck , "yes") == 0){
				printf("enter your promocode: \n");
				scanf("%s" , &promocode);
				if (strcmp(promocode , "Eid2025") == 0){
					discapplied = 1;
					newbill = amount - (amount * 0.25);
					printf("25 percent discount applied\n");
					printf("bill after discount is: %.2f\n" , newbill);
				}	
				else {
					printf("invalid code\n");
				}
			}
				if (discapplied == 1){
					printf("final payment: %.2f\n" , newbill);
					printf("   SUPERMARKET MANAGEMENNT SYSTEM   \n");
					printf("chose any one of the following options:\n");
					printf("1- input customer information\n");
					printf("2- display inventory\n");
					printf("3- add item to cart\n");
					printf("4- display total bill\n");
					printf("5- display invoice\n");
					printf("6- EXIT\n");
					scanf("%d" , &choice);
				}
				else 
				{
					printf("final payment: %.2f\n" , amount);
					printf("   SUPERMARKET MANAGEMENNT SYSTEM   \n");
					printf("chose any one of the following options:\n");
					printf("1- input customer information\n");
					printf("2- display inventory\n");
					printf("3- add item to cart\n");
					printf("4- display total bill\n");
					printf("5- display invoice\n");
					printf("6- EXIT\n");
					scanf("%d" , &choice);
				}
}

void invoice(){
				if (cartindex == 0){
				printf("NO PURCHASING DONE\n");
				printf("   SUPERMARKET MANAGEMENNT SYSTEM   \n");
				printf("chose any one of the following options:\n");
				printf("1- input customer information\n");
				printf("2- display inventory\n");
				printf("3- add item to cart\n");
				printf("4- display total bill\n");
				printf("5- display invoice\n");
				printf("6- EXIT\n");
				scanf("%d" , &choice);
			}
			else {
				printf("   INVOICE   \n");
				printf("customer name: %s\n" , name);
				printf("customer cnic number: %i\n" , CNIC);
				printf("payment before discount: %.2f\n" , amount);
				printf("payment after discount: %.2f\n" , newbill);
				printf("\n");
				printf("   SUPERMARKET MANAGEMENNT SYSTEM   \n");
				printf("chose any one of the following options:\n");
				printf("1- input customer information\n");
				printf("2- display inventory\n");
				printf("3- add item to cart\n");
				printf("4- display total bill\n");
				printf("5- display invoice\n");
				printf("6- EXIT\n");
				scanf("%d" , &choice);
				
			}
}

main(){

	
	printf("   SUPERMARKET MANAGEMENNT SYSTEM   \n");
	printf("chose any one of the following options:\n");
	printf("1- input customer information\n");
	printf("2- display inventory\n");
	printf("3- add item to cart\n");
	printf("4- display total bill\n");
	printf("5- display invoice\n");
	printf("6- EXIT\n");
	scanf("%d" , &choice);
	
	while (choice >=1 && choice <= 6){
		if (choice == 1){
			customerinfo();
		}
		
		else if (choice == 2){
			inventory();
		}
		
		else if (choice == 3){
			addtocart();
		}
		
		else if (choice == 4){
			displaybill();
		}	
		
		else if (choice == 5){
			invoice();
		}
		
		else if (choice == 6){
			printf("system exit.GOODBYE\n");
			break;
		}
	}
}