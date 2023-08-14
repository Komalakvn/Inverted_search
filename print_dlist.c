#include<stdio.h>
#include "main.h"
#include <string.h>

int print_dlist(Dlist *head)
{
 printf("The files in dlist\n");   
 while(head != NULL)
 {
   printf("%s\n",head->file_name);
   head = head->next;
 }

 return SUCCESS;
}

