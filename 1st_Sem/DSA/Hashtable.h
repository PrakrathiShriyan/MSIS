// Insert Names in alphabetical order
//----------------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0
#define NAME_SIZE 20

// Structure definition of node
typedef struct _node_ Node;
struct _node_{
    char name[NAME_SIZE];  // Data
    Node *ptr; // Next node pointer
};

// Structure definition of list
typedef struct _list_ List;
struct _list_{
	int count;  // Count of elements
    Node *head; // Head
	Node *tail; // Tail
};

// Function to create and initialize list
List *initialize_list();

// Function to initialize hash table
List **initialize_ht(int size);

// Function to search entry within hash table
int search_ht(List **my_table, char *name, int size);

// Function to insert
int insert_ht(List **my_table, char *name, int size);

// Function to delete element
int delete_ht(List **my_table, char *name, int size);

// Function to print hash table
void print(List** my_table, int size);