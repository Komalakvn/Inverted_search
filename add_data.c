#include<stdio.h>
#include"main.h"
#include<string.h>
/* Function To Store New Data to the Data Base */
int add_data(Dlist **head,Dlist **tail,M_node **d_base)
{
    char file[20];  
    /* Asking for input */
    printf("Enter your file name: ");
    scanf("%s",file);

    /* Validating the file is .txt , presence , Non emptyfile */
    if(strstr(file,".txt"))
    {
	FILE *fp = fopen(file,"r");  
	if(fp)
	{
	    fseek(fp,0,SEEK_END);
	    if(ftell(fp))          
	    {
              if(store_filename(file,head,tail) == SUCCESS)    
	      {
	        if(create_database(*tail,d_base) == SUCCESS)  
		{
		  return SUCCESS;
		
		}

	      }

	    }
	}	
    }
    return FAILURE;

}

