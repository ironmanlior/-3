#include "StrList.h"
#include <stdio.h>
#include <string.h>

StrList* list = NULL;


void insert_string(){
	int num;

	list = StrList_alloc();

	printf("input numer of words to the list\n");
	scanf("%d", &num);

	printf("input string to the list\n");
	for (int i = 0; i < num; i++){
		char w[256];
		scanf("%s", w);
		StrList_insertLast(list, w);
	}
}

void insert_at(){
	int index;
	char string[256];
	printf("input index to the list\n");
	scanf("%d", &index);

	printf("input string to the list\n");
	scanf("%s", string);

	StrList_insertAt(list, string, index);
}

void print(){
	StrList_print(list);
}

void print_length(){
	printf("%ld\n", StrList_size(list));
}

void print_at(){
	int index;
	printf("input index to the list\n");
	scanf("%d", &index);
	StrList_printAt(list, index);
}

void print_num_chars(){
	StrList_printLen(list);
}

void count(){
	char string[256];
	printf("input string to the list\n");
	scanf("%s", string);

	printf("%d\n", StrList_count(list, string));
}

void remove_element(){
	char string[256];
	printf("input string to the list\n");
	scanf("%s", string);
	StrList_remove(list, string);
}

void remove_at(){
	int index;
	printf("input index to the list\n");
	scanf("%d\n", &index);
	StrList_removeAt(list, index);
}

void reverse(){
	StrList_reverse(list);
}

void delete(){
	StrList_free(list);
	list = NULL;
}

void sort(){
	StrList_sort(list);
}

void is_sorted(){
	printf("%d\n", StrList_isSorted(list));
}

int main(void){
	while (1) {
		int input;
		//printf("enter number between 0 and 13\n");
		scanf("%d",&input);
		if (input == 0) break;
		else if (input == 1)
			insert_string();
		else if (input == 2)
			insert_at();
		else if (input == 3)
			print();
		else if (input == 4)
			print_length();
		else if (input == 5)
			print_at();
		else if (input == 6)
			print_num_chars();
		else if (input == 7)
			count();
		else if (input == 8)
			remove_element();
		else if (input == 9)
			remove_at();
		else if (input == 10)
			reverse();
		else if (input == 11)
			delete();
		else if (input == 12)
			sort();
		else if (input == 13)
			is_sorted();
	}
	
	return 0;
}