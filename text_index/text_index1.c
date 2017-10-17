#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct file_t      //structure defnition of file_table
{
	char file_name[100];
	int word_count;
}file_table;

typedef struct node //structure defnition hash_node
{
	char word[100];
	int file_count;
	file_table *ft;
	struct node *next;
}hash_node;

int hash_text(char *key) //hash_function defnition
{

	unsigned char c = *key;  //assigning first index to to c
	if(isupper(c))
		tolower(c);
	return (c-97); //returning the obtained index value
}

hash_node *create_text_node(char *word , char *file_name ) //function defnition for create node
{
	hash_node*new = calloc(sizeof(hash_node), 1); //creatind a new node of structure hashnode
	file_table*table =  calloc(sizeof(file_table), 1); //taking a dynamic array using calloc

	strcpy(table->file_name , file_name);  //initializing first element variables
	table->word_count++;
	if(new != NULL)
	{
		strcpy(new->word , word);  //assigning values for the node created
		new->file_count++;
		new->ft = table;
		new->next = NULL; //making next address as null
	}
	else
		printf("Sorry ! no memory\n");  //if no memory is allocated
	return new;
}

void file_word_count(hash_node*head , char*name ) //function defnition for file_word_count
{
	file_table*ptr = (head)->ft;//taking ptr as file_table pointer
	int i = 0;
	while(1)
	{
		if(!strcmp((head)->ft[i].file_name, name)) ///checking passed file name is same as the nam pointed by pointer
		{
			(head)->ft[i].word_count++; //if true increment the word count
			break;
		}
		else if(!strcmp((head)->ft[i].file_name,"")) //checking the data is present or not in that location
		{
			(head)->file_count++; //if true increment the file count
			strcpy((head)->ft[i].file_name, name);//copy the file name to the location
			(head)->ft[i].word_count++; //increment the word count
			return;//break the loop
		}
		else
			i++;//else increment i
	}
}


void create_new_text_node(hash_node **head , char *word , char *file_name ) //function defnition create new node
{
	if(*head == NULL)//checking the head for null condition
	{

		*head = create_text_node(word , file_name );//assigning head with create tex node
	}

	else//else
	{
		hash_node*ptr = *head; //taking ptr as head
		while(ptr->next != NULL)
		{
			if(!strcmp(ptr->word , word)) //checking each node with the word
			{//if true
				file_word_count(ptr , file_name )	;//call file_count_word function
				return;//ret
			}
			else
				ptr = ptr->next; //move ptr to next node


		}
		if(!strcmp(ptr->word , word))  //if the last contains the word passed
		{
			file_word_count(ptr , file_name )	;//call
			return;
		}
		else

		{
			ptr->next = create_text_node(word , file_name) ; //else assign the node of that word node created
		}
	}
}
void print_details(hash_node*head , int count)//function defnition
{
	hash_node*ptr =head; //taking ptr to head
	int i;
	while(ptr != NULL)//traversing the loop untill null
	{
			printf("\nword: \"%s\" \n", ptr->word);
			printf("file_count : \t%d \n", ptr->file_count);
			printf("\nFILE_TABLE:\n");
			printf("┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
			printf("File_name\t   word_count\n");
			printf("┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
			for(i = 0 ; i < count ; i++) //printing the file table array
			{
				if(ptr->ft[i].word_count != 0)
				{
					printf("%s\t\t\t", ptr->ft[i].file_name);//printing the file name with the word count
					printf("%d\n", ptr->ft[i].word_count);
			printf("┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
				}
			}
			printf("\n");
		ptr= ptr->next;
		}
	}

void file_open(FILE *fp , hash_node*array[] , char *file_name)//function defnition
{
printf("HI\n");
	int i = 0;
	char arr[100]  ;//declaring the variables
	char ch;
	while(1)
	{
		i = 0;
		while((ch=fgetc(fp)) != ' ' ) //extracting each word in the file
		{
			if(ch  == EOF  || ch == '\n')  //at the same time checking foe eof and newline character
				break;
			arr[i] = ch;//assigning each element with the character from the file
			i++;
		}
		if(ch  == EOF)
			break;
		arr[i] = '\0';//assigning the last location as null
		if(arr[0] != '\0')
		{
			create_new_text_node(&array[hash_text(arr)] , arr , file_name  );//calling create node function

		}
	}
	fclose(fp);//closing the file

}


void search_word(hash_node*head, char *word , int count) //function defnition search word 
{

	hash_node*ptr = head; //taking ptr as head
	int i;
	while(ptr != NULL) //traversing all the nodes until null
	{
		if(!strcmp(ptr->word , word)) //checking the word entred with word in the node
		{
			printf("The details for the word"); //printing the details found in the node
			printf("\n\"%s\" are:\n\n", ptr->word);
			printf("file_count : \t%d \n", ptr->file_count);
			printf("\n\nFILE_TABLE:\n");
			printf("┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
			printf("File_name\t   word_count\n");
			printf("┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
			for(i = 0 ; i < count ; i++) //printing the file table array
			{
				if(ptr->ft[i].word_count != 0.0)
				{
					printf("%s\t\t\t", ptr->ft[i].file_name);//printing the file name with the word count
					printf("%d\n", ptr->ft[i].word_count);
			printf("┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
				}
			}
			return;
		}
		else
			ptr = ptr->next;//else increment the pointer to next node
	}
	printf("Sorry No word found\n");//if all the nodes are over no word is found
}
