#include<stdio.h>
#include "main.h"
#include<stdlib.h>
#include<string.h>

/* To store the all files is a Double Linked list */
int store_filename(char *file,Dlist **head,Dlist **tail)
{
    /* Allocating new node */
    Dlist *new = malloc(sizeof(Dlist));   
    strcpy(new->file_name,file);    

    /* If the list is empty */
    if(*head == NULL)
    {
	*head = new;
	*tail = new;
	new->prev = NULL;
	new->next = NULL;
    }

    /* If the list is not empty */
    else
    {
	new->prev = *tail;
	new->next = NULL;
	(*tail)->next = new;
	*tail = new;
	return SUCCESS;
    } 
}

