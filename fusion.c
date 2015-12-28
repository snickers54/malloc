/*
** fusion.c for  in /home/single_j//projets/malloc
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Thu Feb  3 18:11:18 2011 julien singler
** Last update Fri Feb 11 22:26:16 2011 julien singler
*/

#include "my_malloc.h"

chunk		*fusion()
{
  chunk		*temp;
  size_t	i;
  chunk		*older;

  older = 0;
  for (i = 0, temp = chunkList; temp; temp = temp->next)
    if (temp->used == 0)
      {
  	older = temp;
  	if (older->next && older->next->used == 0)
  	  {
  	    del_to_hash(older);
  	    del_to_hash(older->next);
  	    older->real_size += older->next->real_size;
  	    older->size += older->next->size + sizeof(*older);
  	    older->next = older->next->next;
  	    break;
  	  }
  	older = 0;
      }
  return older;
}
