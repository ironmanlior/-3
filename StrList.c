#include "StrList.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node {
	char* data;
	struct _Node* next;
} Node;

struct _StrList {
	Node* head;
	size_t size;
};

Node* node_alloc(const char* data, Node* next){
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = (char*) malloc(sizeof(char) * strlen(data));
	strcpy(node->data, data);
	node->next = next;
	return node;
}

void node_free(Node* node){
	if (node == NULL) return;
	free(node->data);
	free(node);
}

StrList* StrList_alloc(){
	StrList* list = (StrList*) malloc(sizeof(StrList));
	list->head = NULL;
	list->size = 0;
	return list;
}

void StrList_free(StrList* str_list){
	if (str_list == NULL) return;
	Node* temp;
	while (str_list->head != NULL) {
		temp = str_list->head;
		str_list->head = str_list->head->next;
		node_free(temp);
	}
	free(str_list);
}

size_t StrList_size(const StrList* StrList){
	return StrList->size;
}

void StrList_insertLast(StrList* StrList, const char* data){
	StrList_insertAt(StrList, data, StrList->size);
}

void StrList_insertAt(StrList* StrList, const char* data, int index){
	Node* temp = node_alloc(data, NULL);

	Node** last = &(StrList->head);
	for (int i = 1; i < index; i++) last = &((*last)->next);
	if (*last != NULL){
		temp->next = (*last)->next;
		(*last)->next = temp;
	} else *last = temp;
	
	printf("%s", temp->data);
	StrList->size++;
}

char* StrList_firstData(const StrList* StrList){
	return StrList->head->data;
}

void StrList_print(const StrList* StrList){
	Node* p = StrList->head;
	while (p != NULL){
		printf("%s %s ", p->data, (p->next != NULL) ? "->" : "\n");
		p = p->next;
	}
}

void StrList_printAt(const StrList* Strlist,int index){
	// like in python for convenience
	if (index < 0) index = Strlist->size - index;
	else if (index >= Strlist->size) index = index % Strlist->size;

	Node* p = Strlist->head;
	for (int i = 0; i <= index; i++) p = p->next;
	printf("%s\n", p->data);
}

int StrList_printLen(const StrList* Strlist){
	int len = 0;
	Node* current = Strlist->head;
	while (current->next != NULL){
		len += strlen(current->data);
	}
	return len;
}

int StrList_count(StrList* StrList, const char* data){
	int count = 0;
	Node* current = StrList->head;
	while (current->next != NULL){
		if (strcmp(data, current->data) == 0) count++;
	}
	return count;
}

void StrList_remove(StrList* StrList, const char* data){
	Node* current = StrList->head;
	while (current->next != NULL){
		if (strcmp(data, current->data) == 0) {
			Node* temp = current->next;
			current->next = current->next->next;
			node_free(temp);
		}
	}
}

void StrList_removeAt(StrList* StrList, int index){
	Node* prev = StrList->head;
	// prev will be 1 place before the index we want to remove
	for (int i = 1; i < index; i++) prev = prev->next;

	Node* temp = prev->next;
	prev->next = prev->next->next;
	node_free(temp);
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
	Node* p1 = StrList1->head;
	Node* p2 = StrList2->head;

	while (p1 && p2){
		if (strcmp(p1->data, p2->data) != 0)
			return 0;

		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1 == NULL && p2 == NULL) return 0;
	return 1;
}

StrList* StrList_clone(const StrList* Strlist){
	Node* old = Strlist->head;
	StrList* list = StrList_alloc();
	list->size = Strlist->size;
	Node** copy = &(list->head);
	while (old){
		*copy = node_alloc(old->data, NULL);
		old = old->next;
		copy = &((*copy)->next);
	}
	return list;
}



void StrList_reverse( StrList* Strlist){
	Node* prev = NULL;
	Node* current = Strlist->head;
	Node* next = NULL;
	while (current){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	Strlist->head = prev;
}

void StrList_sort(StrList* Strlist){
	if(Strlist == NULL || Strlist->head == NULL) return;  
	Node *current = Strlist->head, *index = NULL;  
	char* temp;  
	
	while(current != NULL) {  
		index = current->next;  
			
		while(index != NULL) {  
			//If current node's data is greater than index's node data, swap the data between them  
			if(current->data > index->data) {  
				temp = current->data;  
				current->data = index->data;  
				index->data = temp;  
			}  
			index = index->next;  
		}  
		current = current->next;  
	}      
}

int StrList_isSorted(StrList* Strlist){
	Node* node = Strlist->head;

	while (node->next != NULL){
		if (strcmp(node->data, node->next->data) > 0) return 0;
		node = node->next;
	}
	return 1;
}