#ifndef TEXT_INDEX
#define TEXT_INDEX
typedef struct file_t
{
	char file_name[100];
	double word_count;
	struct file_t *link;
}file_table;

typedef struct node
{
	char word[100];
	double file_count;
	file_table *ft;
	struct node *next;
}hash_node;

int hash_text(char *key);
hash_node *create_text_node(char *word );
void file_word_count(file_table*ptr , char*name , int *count);

void create_new_text_node(hash_node **head , char *word , char *file_name);
void file_open(FILE *fp , hash_node*array[] , char *file_name);
void print_details(hash_node*head , int count);
void search_word(hash_node*head, char *word , int count);


#endif





