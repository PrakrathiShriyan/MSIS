#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Hashtable.h"

// Function to create and initialize list
List *initialize_list(){

    List *my_list;

	// Allocate memory for list
	my_list = (List *)malloc(sizeof(List));

	if(my_list == NULL)
		return NULL; // Memory allocation failed

    my_list->head = NULL;
	my_list->tail = NULL;
	my_list->count = 0;

    return my_list; // Return list pointer
}

// Function to initialize hash table
List **initialize_ht(int size){
	List **my_table;
	int i;
	
	// Allocate memory for double pointer
	my_table = (List **)malloc(sizeof(List *)*size);
	
	// Allocate memory for lists
	for(i=0; i<size; i++)
		my_table[i] = initialize_list();
	
	return my_table;
}

// Function to create node
Node *create_node(char *name){
	
	Node *new_node; // Pointer for new node
	
	// Allocate memory for node
	new_node = (Node *)malloc(sizeof(Node));
	
	if(new_node == NULL)
		return NULL; // Memory allocation failed
	
	strcpy(new_node->name, name);
	new_node->ptr  = NULL;
	
	return new_node;
}

// Hash Function
int hash(char *name, int size){
	char ch;
	
	ch = name[0];
	
	return (toupper(ch) - 'A')%size;
}

// Function to search given element within list
int search_list(List *my_list, char *name){
	Node* temp;
	
	// If list is empty, no point in searching element
	if(my_list->count == 0)
		return FAILURE;
	
	// Iterate through list until element is found
	for(temp = my_list->head;
	    temp != NULL; 
		temp = temp->ptr){
			
	    if(strcmp(temp->name, name))
			return SUCCESS;
	}
	
	return FAILURE;
	
}

// Function to insert element to list
int insert_list(List *my_list, char *name){
	Node *new_node;
	
	new_node = create_node(name);
	
	if(my_list->head == NULL){
	// Inserting First Element
	    my_list->head = new_node;
		my_list->tail = new_node;
	}
	else{
	// Inserting elements
		new_node->ptr = my_list->head;
		my_list->head = new_node;
	}
	
	my_list->count ++;
	return SUCCESS;
}

// Function to insert
int insert_ht(List **my_table, char *name, int size){
	int index;
	List *my_list;
	
    index = hash(name, size);
	my_list = my_table[index];

	return insert_list(my_list, name);
}

// Function to print hash table
void print(List** my_table, int size){
	int i;
	Node *temp;
	
	for(i = 0; i<size; i++){
		printf("Index[%d]: ", i);
		
		temp = my_table[i]->head;
		while(temp != NULL){
			printf("%s -> ", temp->name);
			temp = temp->ptr;
		}
		printf("NULL\n");
	}
}

// Function to delete element in list
int delete_element(List *my_list, char *name){
	Node *prev;
	Node *temp;
	
	// If list is empty
	if(my_list->count == 0 || my_list == NULL)
		return FAILURE;
	
	prev = NULL;
	temp = my_list->head;
	
	// Iterate through list until element is found
	while(temp != NULL && strcmp(temp->name, name)){
		prev = temp;
		temp = temp->ptr;
	}
	
	// Element not found
	if(temp == NULL)
		return FAILURE;
	
	// If element to be deleted is at head
	if(prev == NULL){
		my_list->head = temp->ptr;
		if(my_list->count == 1){
		// If it was only element
		    my_list->tail = NULL;
		}
	}
	else{
		prev->ptr = temp->ptr;
		// If element to be deleted is at tail
		if(temp == my_list->tail){
			my_list->tail = prev;
		}
	}
	
	free(temp);
	
	my_list->count --;
	
	return SUCCESS;
}

// Function to delete data
int delete_ht(List **my_table, char *name, int size){
	int index;
	List *my_list;
	
	index = hash(name, size);
	my_list = my_table[index];
	
	return delete_element(my_list, name);
}

// Function to search entry within hash table
int search_ht(List **my_table, char *name, int size){
	int index;
	List *my_list;
	
	index = hash(name, size);
	my_list = my_table[index];
	
	return search_list(my_list, name);
}