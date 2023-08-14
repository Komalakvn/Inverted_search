#include<stdio.h>
#include "main.h"
#include<string.h>

/* To save Data Base in a file */
int save_data(M_node **d_base )
{
    /* Declaring array to store file name */
    char out_file[20];
    M_node *temp = NULL;  

    /* Asking user for input */
    printf("Enter output file name:");
    scanf("%s",out_file); 
    /* If the input is not a .txt file then remove given extension and make it .txt file */
    if(strcmp(out_file,".txt") != 0)
    {
	strtok(out_file,".");
	strcat(out_file,".txt");   
    }
    /* Opening the File */
    FILE *fptr = fopen(out_file,"w");
    for(int i = 0;i < 27;i++)  
    {
	temp = d_base[i];     
	while(temp != NULL)   
	{
	    /* Printing the details with starting '#' and ending with '#'*/
            fprintf(fptr,"%c",'#');
	    fprintf(fptr,"%d;",i);
	    fprintf(fptr,"%s;",temp->word);
	    fprintf(fptr,"%d;",temp->file_count);
	    S_node *s_temp = temp->s_link;
	    /* Traversing all subnode */
	    while(s_temp != NULL)
	    {
		fprintf(fptr,"%s;",s_temp->file_name);
		fprintf(fptr,"%d;",s_temp->word_count);

		s_temp = s_temp->link;
	    }
	    fprintf(fptr,"%c",'#');
	    fprintf(fptr,"\n");
            temp = temp->m_link;
	}
    }
    return SUCCESS;

}

