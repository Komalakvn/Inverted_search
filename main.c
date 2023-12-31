#include<stdio.h>
#include "main.h"
#include<string.h>

/*
Name:Komala KV
Title: Inverted Search
 */

int main(int argc, char *argv[])
{
    /* Declaring head and tail of Dlist */
    Dlist *head = NULL;
    Dlist *tail = NULL;
    /* Declaring hash_table array*/
    M_node *d_base[27] = {NULL};                      
    if(argc >= 2)                                    
    {
	for(int i = 1;i < argc;i++)                    
	{
	    if(strstr(argv[i],".txt"))                 // the given argument is .txt or not
	    {

		if(fopen(argv[i],"r"))                 // Checking the file is present or not
		{
		    FILE *fp = fopen(argv[i],"r");      //file opening
		    fseek(fp,0,SEEK_END);              // Setting the file pointer to last character of the .txt file
		    if(ftell(fp))                      // Checking file is empty or nor
		    {
			store_filename(argv[i],&head,&tail);              // After validating all the condition storing in double linked list
#ifdef DLIST
			print_dlist(head);                              
#endif	  
		    }
		    else
		    {
			printf("Error: %s is an empty file\n",argv[i]);    // printf if the file is empty
		    }
		}
		else
		{
		    printf("Error: The %s is not present\n",argv[i]);      // print if the file is not present in the directory
		}
	    }
	    else
	    {
		printf("%s is not a .txt file\n",argv[i]);                 // If the file is not having extension .txt..
	    }
	}
    }
    /* If the number argument is wrong */
    else
    {
	printf("Error: Invalid input\n");
	printf("Usage: Pass More than two argument\n");
	return 0;
    }
    /* Declaring Variables and char array */
    int ch=0;          
    char ch1='y';      
    int flag = 0;
    char data[20];
    while(1)
    {
	if(ch1 == 'y')
	{	  
	    printf("1. Create Database\n2.Display Database\n3.Search Database\n4.Save Database\n5.Update Database\n6.Add Data\n7.Exit\n");
	    printf("Enter your choice: ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		/* If the user choose to create data base */
		case 1:
		    if(flag == 0)                                    
		    {
			if(create_database(head, d_base) == SUCCESS)    
			{
			    printf("SUCCESS: Database created Successfully\n");
			    flag = 1;
			}
			else
			{
			    printf("Error:Data base create unsuccess\n");
			}
		    }
		    else
			printf("Error: Database already created\n");
		    break;
		    /* To Perform Display Data Base */    
		case 2:
		    if(flag == 1)
		    {
			if(display_data(d_base) == SUCCESS)
			    printf("Success: Data Displayed succesfully\n");
		    }
		    else
		    {

			printf("Error: Data Base not created\n");
		    }
		    break;
		    /* To perform Search Data In Data Base */    
		case 3:
		    printf("Enter your data: ");
		    scanf("%s",data);
		    if(search_data(d_base,data) == SUCCESS)
			printf("Success:Data found Successfully\n");
		    else
			printf("Error:Data not found\n");
		    break;
		    /* To perform Save data in a file */		    
		case 4:
		    if(flag == 1)
		    {
			if(save_data(d_base) == SUCCESS)
			    printf("Success: Data saved\n");
		    }
		    else
			printf("Error:Data not present in Data Base\n");
		    break;
		    /* To Perform Update Data Base */    
		case 5:
		    /* This function can be perform if the create database not performed */
		    if(flag == 0)
		    {
			if(update_database(d_base) == SUCCESS)
			{
			    printf("Success:Database Updated Successfully\n");
			    flag = 1;
			}
			else
			    printf("Error:Database not Updated\n");
		    }
		    else
		    {
			printf("Error:Database Update not possible\n");
		    }
		    break;
		    /* To add new data to the Data Base */		    
		case 6:
		    if(add_data(&head,&tail,d_base) == SUCCESS)
		    {
			printf("Success:Data Added Successfully\n");
		    }
		    else
			printf("Error:Data not added\n");
		    break; 
		    /* To Stop the Programm */		    
		case 7:
		    return 0;
		    break;    
		default:
		    printf("Invalid Choice\n");


	    }
	}
	else
	{
	    return 0;
	}
	printf("Do you want to continue:y/n: ");
	getchar();
	scanf("%c",&ch1);

    }
    return 0;
}



