/**
 * CUSTOMER-INTEREST-ANALYSIS
 *
 * Customer Interest is a technique in which we divide the customers
 * based on their purchase history, gender, age, interest, etc. It is useful
 * to get this information so that the store can get help in personalize
 * marketing and provide customers with relevant deals.
 *
 * FUNCTIONALITIES:
 *  	1. ADD PURCHASE DETAILS
 *  	2. FIND MOST FREQUENTLY PURCHASED ITEMS
 *  	3. FIND MOST VISITED CUSTOMER
 *  	4. FIND LIST OF ITEMS BASED ON FREQUENCY COUNT FOR A GIVEN AGE GENDER RANGE
 *  	5. FIND AGE RANGE OF CUSTOMERS WHO PURCHASED A GIVEN ITEM
 *
 * @file main.cpp
 * @brief analyse the customer data, extract and store useful information.
 *
 * @author Abishek M
 * @author Diwakar R
 * @author Hari Varsha V
 * @author Krishna Prasath R
 * @author Rahul Rajeev Pillai
 *
 */
#include <stdio.h>
#include <string.h>
#define MAX 100
#define MIN 10

/**
 * Implementation of a data-structure to store customer data
 *
 * This structure will hold customer's data like their age, gender, name,
 * data-of-purchase and the list of items purchased.
 *
 */
struct customer{
	int age;
	char gender;
	char date[10];
	char name[MIN+20];
	char mobileNumber[MIN];
	char items[MAX][MIN+10];
};

/*
// FUNCTION DEFINITIONS
void add_customer(int mobileNumber, char name[], int age, char gender,char
date[], char items[][20]);

char* frequentlyPurchasedItems(struct customer data[]);

char* mostVisitedCustomer(struct customer data[]);

char* itemsPurchasedInrange(struct customerData[], int ageMin,int ageMax, int gender);

int* ageRange(struct customer data[], int ageMin, int ageMax);
*/


int main()
{
    // driver code
	struct customer customer_data[MAX];
	int option = 0, ageMin, ageMax, n, N;
	while(option != -1){

		// INPUTS:
		printf("Enter 1 to add purchase details of the customer\n");
		printf("Enter 2 to find most frequently purchased item\n");
		printf("Enter 3 to find the most visited customer\n");
		printf("Enter 4 to print the list of items purchased by the give age range and gender\n");
		printf("Enter 5 to find the age range of those who purchased the given item\n");
		printf("Enter the option: ");

		scanf("%i", &option);
		while ((getchar()) != '\n');

		switch(option){
			case 1:
				// INPUTS:
				printf("\nEnter mobile number: ");
				fgets(customer_data[N].mobileNumber, MIN, stdin);
				while ((getchar()) != '\n');

				printf("\nEnter name of the customer: ");
				fgets(customer_data[N].name, MIN+10, stdin);
				while ((getchar()) != '\n');

				printf("\nEnter the gender: ");
				scanf("%c ", customer_data[N].gender);
				while ((getchar()) != '\n');

				printf("\nEnter the date of purchase in the format(dd-mm-yyy): ");
				fgets(customer_data[N].date, MIN, stdin);
				while ((getchar()) != '\n');

/*
				printf("Enter the number of items purchased: ");
				scanf("%i", n);

				for(int i=0; i<n; i++){
					printf("Enter the item %i ", i+1);
					fgets(customer_data[N].items[i], MIN+10, stdin);
				}
				*/

				printf("%s %s %c %s", customer_data[N].mobileNumber,
				customer_data[N].name, customer_data[N].gender,
				customer_data[N].date); 
		}

		++N;

	}
	return 0;
}

/*
void addCustomer(int mobileNumber, char name[], int age, char gender,char date[], char items[][MAX])
{

//code goes here  @ user

}

char* frequentlyPurchasedItems(struct customer data[])
{

//code goes here @ user

}

char* mostVisitedCustomer(struct customer data[]);
{

//code goes here @ user


}

char* itemsPurchasedInrange(struct customer data[], int ageMin,int ageMax, int gender)
{

//code goes here @ user

}

int* ageRange(struct customer data[], int ageMin, int ageMax)
{

//code goes here @ user

}
*/
