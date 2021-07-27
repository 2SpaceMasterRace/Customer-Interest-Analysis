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
#include "utils.c"

char ITEMS[MAX][10] = {
	"Jersey", "Shirts", "Jeans", "Jackets", "Pants",
		"Coats", "Blazers", "Tuxedo", "Tracks ",
};

typedef struct{
	int age, gender, items[20], items_size;
	char name[30];
	long mobileNumber;
}customer;

// FUNCTION DEFINITIONS
void add_customer(customer customer_data[], int x);
void frequentlyPurchasedItems(customer data[], int size);
void mostVisitedCustomer(customer data[], int size);
void ageRange(customer data[], int size, int item);
void itemsPurchasedInrange(customer customer_data[], int ageMin, int size,
                           int ageMax, int gender);

void newlines(int num);
void tabs(int num);

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
				printf("Press 1 for Jersey\n");
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
				printf("Press 9 for Track suit\n");
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

void newlines(int num){
	for(int i=0; i<num; i++){
		printf("\n");
	}
}

void tabs(int num){
	for(int i=0; i<num; i++){
		printf("\t");
	}
}

void mostVisitedCustomer(customer data[], int size){
	long number[MAX], *new_number;
	int k = 0, index = 0, count[MAX]={};
	for(int i=0; i<size; i++){
		number[index++] = data[i].mobileNumber;
	}
	sort(number, index, sizeof(long), compare_long_sort);
	new_number = common(number, sizeof(long), index,  &k, compare_long, count);

	int tab = 9;

	system("clear");
	newlines(lines);
	tabs(tab);

	printf("Most Visited Customer\n\n");
	tabs(tab);
	printf("Name\tVisitation Count\n");
	tabs(tab);
	printf("------------------------\n");

	for(int i=0; i<k; i++){
		for(int j=0; j<size; j++){
			if(new_number[i] == data[j].mobileNumber){
				tabs(tab);
				printf("%s - %i\n", data[j].name, count[i]);
				break;
			}
		}
	}
	free(new_number);
}

void frequentlyPurchasedItems(customer data[], int size){
	int items[MAX], k = 0, index = 0, *new_items, count[MAX]={};
	for(int i=0; i<size; i++){
		for(int j=0; j<data[i].items_size; j++){
			items[index++] = data[i].items[j];
		}
	}
	sort(items, index, sizeof(int), compare_int_sort);
	new_items = common(items, sizeof(int), index,  &k, compare_int, count);

	system("clear");
	newlines(lines);

	int tab = 9;

	tabs(tab);
	printf("Frequently purchased items\n\n");
	tabs(tab);
	printf("Items\t\tCount\n");
	tabs(tab);
	printf("---------------------\n");

	for(int i=0; i<k; i++){
		tabs(tab);
		printf("%s\t   |\t%i\n", ITEMS[new_items[i] - 1], count[i]);
	}
	free(new_items);
}

void itemsPurchasedInrange(customer customer_data[], int ageMin, int size,
                           int ageMax, int gender){
	int items[MAX], count[MAX] = {}, k = 0, index = 0, *new_items;
	for(int i=0; i<size; i++){
		if(customer_data[i].age >= ageMin &&
		   customer_data[i].age <= ageMax &&
		   customer_data[i].gender == gender){
			for(int j=0; j<customer_data[i].items_size; j++){
				items[index++] = customer_data[i].items[j];
			}
		}
	}
	sort(items, index, sizeof(int), compare_int_sort);
	new_items = common(items, sizeof(int), index,  &k, compare_int, count);

	system("clear");
	newlines(lines);
	tabs(tab);

	printf("\tFrequently Purchased items based on age and gender\n\n");

	int tab = 9;

	tabs(tab);
	printf("Items\t\tCount\n");
	tabs(tab);
	printf("---------------------\n");

	for(int i=0; i<k; i++){
		tabs(tab);
		printf("%s\t   |\t%i\n", ITEMS[new_items[i] - 1], count[i]);
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
		printf("Press 1 for Jersey\n");
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
		printf("Press 9 for Track suit\n");
		tabs(tab);
		printf("Enter the option: ");
		scanf("%i", &customer_data[x].items[i]);
	}
}

void ageRange(customer customer_data[], int size, int item){
	int age[MAX], index=0;
	for(int i=0; i<size; i++){
		for(int j=0; j<customer_data[i].items_size; j++){
			if(customer_data[i].items[j] == item){
				age[index++] = customer_data[i].age;
			}
		}
	}
	sort(age, index, sizeof(int), compare_int_sort);

	system("clear");
	newlines(lines);
	tabs(tab+2);

	printf("Category : %i - %i age", age[0], age[index-1]);
}
