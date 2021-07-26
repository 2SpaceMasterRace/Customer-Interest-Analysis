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
#include <unistd.h>
#include <stdio.h>
#include "utils.h"

// FUNCTION DEFINITIONS
void add_customer(customer customer_data[], int x);
void frequentlyPurchasedItems(customer data[], int size);
void mostVisitedCustomer(customer data[], int size);
void ageRange(customer data[], int size, int item);
void itemsPurchasedInrange(customer customer_data[], int ageMin, int size,
                           int ageMax, int gender);
int lines = 19;
int tab = 7;

int main()
{
    // driver code
	customer customer_data[MAX];
	int option = -1, ageMin, ageMax, N, gender, item;

	system("clear");
	newlines(lines);
	tabs(tab+2);
	printf("Customer Interest Analysis");
	getchar();

	while(option != 0){
		// INPUTS:
		system("clear");
		newlines(lines);
		tabs(tab);
		printf("Enter 1 to add purchase details of the customer\n");
		tabs(tab);
		printf("Enter 2 to print the list of items purchased by the give age range and gender\n");
		tabs(tab);
		printf("Enter 3 to find the most visited customer\n");
		tabs(tab);
		printf("Enter 4 to find most frequently purchased item\n");
		tabs(tab);
		printf("Enter 5 to find the age range of those who purchased the given item\n");
		tabs(tab);
		printf("Enter 0 to exit\n");
		tabs(tab);
		printf("Enter the option: ");

		scanf("%d", &option);
		getchar();

		switch(option){
			case 1:
				system("clear");
				newlines(lines);
				add_customer(customer_data, N);
				N++;
				break;
			case 2:
				system("clear");
				newlines(lines);
				tabs(tab);
				printf("Press 1 for Male\n");
				tabs(tab);
				printf("Press 2 for Female\n");
				tabs(tab);
				printf("Enter the gender of the customer: ");
				scanf("%i", &gender);
				tabs(tab);
				printf("Enter the age range: ");
				scanf("%i %i", &ageMin, &ageMax);
				getchar();
				itemsPurchasedInrange(customer_data, ageMin, N, ageMax, gender);
				break;
			case 3:
				printf("\n");
				mostVisitedCustomer(customer_data, N);
				break;
			case 4:
				printf("\n");
				frequentlyPurchasedItems(customer_data, N);
				break;
			case 5:
				system("clear");
				newlines(lines);
				tabs(tab);
				printf("Press 1 for T-Shirt\n");
				tabs(tab);
				printf("Press 2 for Shirt\n");
				tabs(tab);
				printf("Press 3 for Jeans\n");
				tabs(tab);
				printf("Press 4 for Jackets\n");
				tabs(tab);
				printf("Press 5 for Pants\n");
				tabs(tab);
				printf("Press 6 for Coats\n");
				tabs(tab);
				printf("Press 7 for Blazers\n");
				tabs(tab);
				printf("Press 8 for Tuxedo\n");
				tabs(tab);
				printf("Press 9 for Sweaters\n");
				tabs(tab);
				printf("Enter the item: ");
				scanf("%i", &item);
				getchar();
				ageRange(customer_data, N, item);
				break;
		}
		getchar();
	}
	return 0;
}

void mostVisitedCustomer(customer data[], int size){
	long number[MAX], *new_number;
	int k = 0, size_i = 0;
	for(int i=0; i<size; i++){
		number[size_i++] = data[i].mobileNumber;
	}
	sort(number, size_i, sizeof(long), compare_long_sort);
	new_number = (long*)common(number, size_i * sizeof(long), size_i,  &k, compare_long);

	system("clear");
	newlines(lines);
	tabs(tab);

	printf("Most Visited Customer : ");

	for(int i=0; i<k; i++){
		for(int j=0; j<size; j++){
			if(new_number[i] == data[j].mobileNumber){
				printf("%s, ", data[j].name);
				break;
			}
		}
	}
	free(new_number);
}

void frequentlyPurchasedItems(customer data[], int size){
	int items[MAX], k = 0, size_i = 0, *new_items;
	for(int i=0; i<size; i++){
		for(int j=0; j<data[i].items_size; j++){
			items[size_i++] = data[i].items[j];
		}
	}
	sort(items, size_i, sizeof(int), compare_int_sort);
	new_items = (int*)common(items, size_i * sizeof(int), size_i,  &k, compare_int);

	system("clear");
	newlines(lines);
	tabs(tab);

	printf("Frequently purchase items : ");

	for(int i=0; i<k; i++){
		printf("%s, ", ITEMS[new_items[i] - 1]);
	}
	free(new_items);
}

void itemsPurchasedInrange(customer customer_data[], int ageMin, int size,
                           int ageMax, int gender){
	int items[MAX], k = 0, size_i = 0, *new_items, tab=9;
	for(int i=0; i<size; i++){
		if(customer_data[i].age >= ageMin &&
		   customer_data[i].age <= ageMax &&
		   customer_data[i].gender == gender){
			for(int j=0; j<customer_data[i].items_size; j++){
				items[size_i++] = customer_data[i].items[j];
			}
		}
	}
	sort(items, size_i, sizeof(int), compare_int_sort);
	new_items = (int*)common(items, size_i * sizeof(int), size_i,  &k, compare_int);

	system("clear");
	newlines(lines);
	tabs(tab);

	printf("Items : ");

	for(int i=0; i<k; i++){
		printf("%s, ", ITEMS[new_items[i] - 1]);
	}
	free(new_items);
}

void add_customer(customer customer_data[], int x){

	tabs(tab);
	printf("Enter the name of the customer: ");
	scanf("%[^\n]%*c", customer_data[x].name);
	
	tabs(tab);
	printf("Enter the mobile number of the cutomer: ");
	scanf("%ld", &customer_data[x].mobileNumber);
	
	tabs(tab);
	printf("Enter the age of the customer: ");
	scanf("%d", &customer_data[x].age);
	getchar();
	
	tabs(tab);
	printf("Press 1 for Male\n");
	tabs(tab);
	printf("Press 2 for Female\n");
	tabs(tab);
	printf("Enter the gender of the customer: ");
	scanf("%i", &customer_data[x].gender);
	getchar();

	tabs(tab);
	printf("Enter the number of items: ");
	scanf("%i", &customer_data[x].items_size);

	int tab = 9;

	for(int i=0; i<customer_data[x].items_size; i++){
		system("clear");
		newlines(lines);
		tabs(tab);
		printf("Press 1 for T-Shirt\n");
		tabs(tab);
		printf("Press 2 for Shirt\n");
		tabs(tab);
		printf("Press 3 for Jeans\n");
		tabs(tab);
		printf("Press 4 for Jackets\n");
		tabs(tab);
		printf("Press 5 for Pants\n");
		tabs(tab);
		printf("Press 6 for Coats\n");
		tabs(tab);
		printf("Press 7 for Blazers\n");
		tabs(tab);
		printf("Press 8 for Tuxedo\n");
		tabs(tab);
		printf("Press 9 for Sweaters\n");
		tabs(tab);
		printf("Enter the option: ");
		scanf("%i", &customer_data[x].items[i]);
	}
}

void ageRange(customer customer_data[], int size, int item){
	int maxage = 0, age;
	for(int i=0; i<size; i++){
		for(int j=0; j<customer_data[i].items_size; j++){
			if(customer_data[i].items[j] == item){
				age = customer_data[i].age;
				if(age > maxage){
					maxage = age;
				}
			}
		}
	}

	system("clear");
	newlines(lines);
	tabs(tab);

	printf("Category : ");

	if(maxage>0 && maxage<18){
		printf("ITEM BELONGS TO UNDER 18 CATEGORY");
	}
	else if (maxage>=18 && maxage<25){
		printf("ITEM BELONGS TO EARLY 20S CATEGORY");
	}
	else if (maxage>=25 && maxage<30 ){
		printf("ITEM BELONGS TO LATE 20S CATEGORY");
	}
	else if (maxage>=30 && maxage<49 ){
		printf("ITEM BELONGS TO MIDDLE AGE CATEGORY");
	}
	else if (maxage>=49 ){
		printf("ITEM BELONGS TO ELDERLY CATEGORY");
	}
}
