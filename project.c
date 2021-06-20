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
	int age;
	char gender;
	char date[10];
	char name[MAX];
	char items[][MAX];
};

// FUNCTION DEFINITIONS
void add_customer(int mobileNumber, char name[], int age, char gender,char date[], char items[][MAX]);

char* frequentlyPurchasedItems(struct customer data[]);

char* mostVisitedCustomer(struct customer data[]);

char* itemsPurchasedInrange(struct customerData[], int ageMin,int ageMax, int gender);

int* ageRange(struct customer data[], int ageMin, int ageMax);


int main()
{
    // driver code
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

//code goes here @ user

}

