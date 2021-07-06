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
 *  	2. FIND LIST OF ITEMS BASED ON FREQUENCY COUNT FOR A GIVEN AGE GENDER RANGE
 *  	3. FIND MOST VISITED CUSTOMER
 *  	4. FIND MOST FREQUENTLY PURCHASED ITEMS
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
#include <stdlib.h>
#define MAX 100

/**
 * Implementation of a data-structure to store customer data
 *
 * This structure will hold customer's data like their age, gender, name,
 * data-of-purchase and the list of items purchased.
 *
 */
typedef struct{
	int age;
	char gender[10];
	char date[10];
	char name[30];
	long mobileNumber;
	int items[20];
	int items_size;
}customer;

char ITEMS[MAX][10] = {"T-Shirt", "Shirt", "Jeans", "Jackets", "Pants"};
char GENDER[2][7] = {"Male", "Gender"};

void sort(int items[], int size){
	int tmp, flag;
	for(int i=0; i<size; i++){
		flag = 1;
		for(int j=0; j<size-1-i; j++){
			if(items[j] > items[j+1]){
				tmp = items[j];
				items[j] = items[j+1];
				items[j+1] = tmp;
				flag = 0;
			}
		}
		if(flag){ break; }
	}
}

int* freq(int arr[], int size, int* j){
	int *new_items = (int*)malloc(5*sizeof(int)), flag = 1;
	for(int i=1; i<size; i++){
		if(arr[i] == arr[i-1] && flag){
			new_items[(*j)++] = arr[i];
			flag = 0;
		}
		else if(arr[i] != arr[i-1]){
			flag = 1;
		}
	}
	return new_items;
}

// FUNCTION DEFINITIONS
void add_customer(customer customer_data[], int x);
void frequentlyPurchasedItems(customer data[], int size);
void mostVisitedCustomer(customer data[], int size);
void ageRange(customer data[], int ageMin, int ageMax);
void itemsPurchasedInrange(customer customer_data[], int ageMin, int size,
                           int ageMax, char gender[]);


int main()
{
    // driver code
	customer customer_data[MAX];
	int option = 0, ageMin, ageMax, n, N, i;
	char gender[10];
	while(option != -1){
		i = 0;

		// INPUTS:
		printf("Enter 1 to add purchase details of the customer\n");
		printf("Enter 2 to print the list of items purchased by the give age range and gender\n");
		printf("Enter 3 to find the most visited customer\n");
		printf("Enter 4 to find most frequently purchased item\n");
		printf("Enter 5 to find the age range of those who purchased the given item\n");
		printf("Enter -1 to exit\n");
		printf("Enter the option: ");

		scanf("%d", &option);
		getchar();

		switch(option){
			case 1:
				add_customer(customer_data, N);
				N++;
				break;
			case 2:
				printf("Enter the gender: ");
				fgets(gender, 10, stdin);
				gender[strcspn(gender, "\n")] = 0;
				printf("Enter the age range: ");
				scanf("%i %i", &ageMin, &ageMax);
				itemsPurchasedInrange(customer_data, ageMin, N+1, ageMax, gender);
				break;
		}
	}
	return 0;
}

void mostVisitedCustomer(customer data[], int size){
	char items[MAX][30];
	int k = 0, size_i = 0, *new_items;
	for(int i=0; i<size; i++){
		strcpy(items[size_i++], data[i].name);
	}
}

void frequentlyPurchasedItems(customer data[], int size){
	int items[MAX], k = 0, size_i = 0, *new_items;
	for(int i=0; i<size; i++){
		for(int j=0; j<data[i].items_size; j++){
			items[size_i++] = data[i].items[j];
		}
	}
	sort(items, size_i);
	new_items = freq(items, size_i, &k);
	for(int i=0; i<k; i++){
		printf("%s ", ITEMS[new_items[i] - 1]);
	}
	printf("\n");
}

void itemsPurchasedInrange(customer customer_data[], int ageMin, int size,
                           int ageMax, char gender[]){
	int items[MAX], k = 0, size_i = 0, *new_items;
	for(int i=0; i<size; i++){
		if(customer_data[i].age >= ageMin &&
		   customer_data[i].age <= ageMax &&
		   !strcmp(customer_data[i].gender, gender)){
			for(int j=0; j<customer_data[i].items_size; j++){
				items[size_i++] = customer_data[i].items[j];
			}
		}
	}
	sort(items, size_i);
	new_items = freq(items, size_i, &k);
	for(int i=0; i<k; i++){
		printf("%s ", ITEMS[new_items[i] - 1]);
	}
	printf("\n");
}

void add_customer(customer customer_data[], int x){
	printf("Enter the name of the customer: ");
	fgets(customer_data[x].name, 30, stdin);
	customer_data[x].name[strcspn(customer_data[x].name, "\n")] = 0;

	printf("Enter the mobile number of the cutomer: ");
	scanf("%ld", &customer_data[x].mobileNumber);

	printf("Enter the age of the customer: ");
	scanf("%d", &customer_data[x].age);
	getchar();

	printf("Enter the gender of the customer: ");
	fgets(customer_data[x].gender, 10, stdin);
	customer_data[x].gender[strcspn(customer_data[x].gender, "\n")] = 0;

	printf("Enter the purchase date: ");
	fgets(customer_data[x].date, 10, stdin);

	printf("Enter the number of items: ");
	scanf("%i", &customer_data[x].items_size);
	for(int i=0; i<customer_data[x].items_size; i++){

		printf("\nPress 1 for T-Shirt");
		printf("\nPress 2 for Shirt");
		printf("\nPress 3 for Jeans");
		printf("\nPress 4 for Jackets");
		printf("\nPress 5 for Pants");
		printf("\nEnter the option: ");
		scanf("%i", &customer_data[x].items[i]);
	}
}

/*
int* ageRange(struct customer customer_data[])
{

// Part by Hari Varsha

	struct customer customer_itemdata;

	printf(" Enter the item you want to find the age range of : ");
	scanf( "%s",customer_itemdata.items);

	for (int i = 0; i < MAX; ++i){
		if(customer_data[i].items==customer_itemdata.items){
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
		}
	}
}
*/
