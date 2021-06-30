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

/**
 * Implementation of a data-structure to store customer data
 *
 * This structure will hold customer's data like their age, gender, name,
 * data-of-purchase and the list of items purchased.
 *
 */
struct customer{
// <<<<<<< testcase
// <<<<<<< HEAD
	int 	;
	char gender;
// =======
	int age;
	char gender[10];
// >>>>>>> c82b73b1ceddf60caed9ea90a7d03a7beb75fc87
// =======
	int age;
	char gender[10];
// >>>>>>> main
	char date[10];
	char name[30];
	long mobileNumber;
	char items[MAX][20];
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
	int option = 0, ageMin, ageMax, n, N, i;
	while(option != -1){
		i = 0;

		// INPUTS:
		printf("Enter 1 to add purchase details of the customer\n");
		printf("Enter 2 to find most frequently purchased item\n");
		printf("Enter 3 to find the most visited customer\n");
		printf("Enter 4 to print the list of items purchased by the give age range and gender\n");
		printf("Enter 5 to find the age range of those who purchased the given item\n");
		printf("Enter -1 to exit\n");
		printf("Enter the option: ");

		scanf("%d", &option);
		getchar();

		switch(option){
			case 1:

				printf("Enter the name of the customer: ");
				fgets(customer_data[N].name, 30, stdin);

				printf("Enter the mobile number of the cutomer: ");
				scanf("%ld", &customer_data[N].mobileNumber);

				printf("Enter the age of the customer: ");
				scanf("%d", &customer_data[N].age);
				getchar();

				printf("Enter the gender of the customer: ");
				fgets(customer_data[N].gender, 10, stdin);

				printf("Enter the purchase date: ");
				fgets(customer_data[N].date, 10, stdin);

				printf("%s, %ld, %d, %s, %s", customer_data[N].name,
				customer_data[N].mobileNumber, customer_data[N].age,
				customer_data[N].gender, customer_data[N].date);
				
				/*
				for(int i=0; i<5; i++){ fgets(customer_data[N].items[i], 10,
				stdin); }

				for(int x=0; x<5; x++){ printf("%s ",
				customer_data[N].items[x]); }
				*/

				break;

		}


	}
	return 0;
}

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

// Part by Hari Varsha

struct customer customer_itemdata;

printf(" Enter the item you want to find the age range of : ");

scanf( " %s ",customer_itemdata.item);

for (int i = 0; i < customer_data[MAX]; ++i)
{

if(customer_data[i].item==customer_customer_itemdata.item)
{

if(customer_data[i].age>0 && customer_data[i].age<18)
	printf(" ITEM BELONGS TO UNDER 18 CATEGORY \n ");

else if (customer_data[i].age>18 && customer_data[i].age<25) 
	printf(" ITEM BELONGS TO EARLY 20S CATEGORY \n ");

else if (customer_data[i].age>25 && customer_data[i].age<30 ) 
	printf(" ITEM BELONGS TO LATE 20S CATEGORY\n ");

else if (customer_data[i].age>30 && customer_data[i].age<49 ) 
	printf(" ITEM BELONGS TO MIDDLE AGE CATEGORY \n ");

else if (customer_data[i].age>49 ) 
	printf(" ITEM BELONGS TO ELDERLY CATEGORY \n ");

else
	printf(" ITEM NOT FOUND \n", );

}

}
