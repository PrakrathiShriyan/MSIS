// 3.
//----------------------------------------------------------------------
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "Hashtable.h"

int main(){
	#define TABLE_SIZE 26
    List **table;
	
	// Test initialization function
    table = initialize_ht(TABLE_SIZE);
	assert(table != NULL);
/*
	// Test insert function
	// A
	assert(insert_ht(table, "Anupam", TABLE_SIZE));
	assert(insert_ht(table, "Adish", TABLE_SIZE));
	assert(insert_ht(table, "Akhil", TABLE_SIZE));
    
	// R
	assert(insert_ht(table, "raja", TABLE_SIZE));
	assert(insert_ht(table, "Ram", TABLE_SIZE));

	// Test Delete Function
	assert(delete_ht(table, "Akhil", TABLE_SIZE) == SUCCESS);
	assert(delete_ht(table, "Ramesh", TABLE_SIZE) == FAILURE);

	print(table, TABLE_SIZE);
	printf("\n");
	
	// Test Search Function
	assert(search_ht(table, "Ram", TABLE_SIZE) == SUCCESS);
	assert(search_ht(table, "Jitesh", TABLE_SIZE) == FAILURE);
*/
	return 0;
}