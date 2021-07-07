/*
 * @file utils.h
 * @brief contains utility code for project.c
 * @author Asborn-SM
 */
#include <stdlib.h>
#include <string.h>
#define MAX 100

char ITEMS[MAX][10] = {"T-Shirt", "Shirt", "Jeans", "Jackets", "Pants"};
char GENDER[2][7] = {"Male", "Gender"};

// FUNTION DEFINITIONS
void swap(void* a, void* b, size_t size);

int compare_long_sort(const void* a, const void* b);
int compare_int_sort(const void* a, const void* b);
int compare_int(const void* a, const void* b);
int compare_long(const void* a, const void* b);

void sort(void* arr, size_t size, size_t d_size, int compare(const void*, const void*));
void* freq(void* arr, size_t size, int len, int* j, int comp(const void*, const void*));

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

void swap(void* a, void* b, size_t size){
	void* temp = malloc(size);
	memcpy(temp, b, size);
	memcpy(b, a, size);
	memcpy(a, temp, size);
	free(temp);
}

int compare_long_sort(const void* a, const void* b){
	long x = *(long*)a;
	long y = *(long*)b;
	return x-y > 0? 1: 0;
}

int compare_int_sort(const void* a, const void* b){
	int x = *(int*)a;
	int y = *(int*)b;
	return x-y;
}

void sort(void* arr, size_t size, size_t d_size, int compare(const void*, const void*)){
	int flag;
	for(int i=0; i<size; i++){
		flag = 1;
		for(int j=0; j<size-1-i; j++){
			if(compare(arr + (j)*d_size, arr + (j+1)*d_size) > 0){
				swap(arr + (j)*d_size, arr + (j+1)*d_size, d_size);
				flag = 0;
			}
		}
		if(flag){
			break;
		}
	}
}

int compare_int(const void* a, const void* b){
	int x = *(int*)a;
	int y = *(int*)b;
	if(x == y){
		return 1;
	}
	return 0;
}

int compare_long(const void* a, const void* b){
	long x = *(long*)a;
	long y = *(long*)b;
	if(x == y){
		return 1;
	}
	return 0;
}

void* freq(void* arr, size_t size, int len, int* j, int comp(const void*, const void*)){
	void* new_items = malloc(size);
	int flag = 1;
	size_t sizeD = size/len;
	for(int i=1; i<len; i++){
		if(comp(arr + i*sizeD, arr + (i-1)*sizeD) && flag){
			memcpy(new_items + ((*j)++)*sizeD, arr + (i)*sizeD, sizeD);
			flag = 0;
		}
		else if(!comp(arr + i*sizeD, arr + (i-1)*sizeD)){
			flag = 1;
		}
	}
	return new_items;
}
