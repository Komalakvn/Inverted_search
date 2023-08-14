#include<stdio.h>
#include "main.h"
#include<stdlib.h>
#include<string.h>
/*
Name : Komala KV
Title :Inverted search project
 */
int create_main_sub_node(M_node *m_prev, char *temp, char *buff)
{
    M_node *m_new = malloc(sizeof(M_node)); 
    S_node *s_new = malloc(sizeof(S_node));
    if(m_new == NULL | s_new == NULL)
    {
      return FAILURE;
    }
   
    s_new->word_count = 1;                          //updating the subnode
    strcpy(s_new->file_name,temp);
    s_new->link = NULL;
                                                   //updating main node
    m_new->file_count = 1;
    strcpy(m_new->word,buff);
    m_new->s_link = s_new;
    m_new->m_link = NULL;
                                                // Updating index with new main Node address
    m_prev->m_link = m_new; 
       return SUCCESS;
}

