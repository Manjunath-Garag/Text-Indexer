#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<text_index.h>

int main(int count , char **file_name) //command line
{
	hash_node*alpha[26] = {0};//taking array of pointers of type hash node
	int i , choice;
	char name[32];
	while(1)
	{
		system("clear");
		printf("Enter the option:\n");//asking user for option
		printf("1.Create-hash_table\n2.Search_word\n3.Print_hash_table\n");
		printf("â”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆâ”ˆ\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				{

					for(i = 1 ; i < count ; i++)
					{
						FILE*fp ;//opening each files in read mode
						if((fp = fopen(file_name[i] , "r")) == NULL)
							printf("No File found\n");
						else
							file_open(fp , alpha , file_name[i]);//else call fil_op function
					}
					//	printf("Creating Hash_table for the  files Is \"SUCCESSFULL\"\n");
				}
				break;
			case 2:
				{
					printf("Enter the word you want to search:");//function call for seacrching a word
					scanf("%s", name);//for the entered searched word
					system("clear");
					search_word(alpha[hash_text(name)], name , count);//function call
				}
				break;
			case 3:
				{
					for(i = 0 ; i < 26 ; i++)
						print_details(alpha[i] , count);//print the whole table

				}
				break;
				/*	case 4:
					{
					printf("Enter the file_name for updating:");
					scanf("%s", name);
					FILE*fp;
					if((fp = fopen(name , "r")) == NULL)
					perror("No File found\n");
					else
					{
					file_open(fp , alpha ,name);
					printf("Update Successfull\n");
					}
					}
					break;
				 */
			case 0:exit(1);
			default:printf("Try Again\n");
		}
		//getchar();
		//getchar();
	}
	return 0;
}
