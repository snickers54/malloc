/*
** show_alloc_mem.c for  in /home/single_j//projets/malloc
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Thu Feb  3 18:12:20 2011 julien singler
** Last update Fri Feb 11 22:02:06 2011 julien singler
*/

#include "my_malloc.h"

void		show_alloc_mem()
{
  chunk		*list;
  int		i;
    size_t	len;
  chunk		*save;

  printf("break : %p\n", sbrk(0));
  for (i = 0, len = 0, save = 0, list = chunkList; list;)
    {
      if (list->used == 1)
	{
	  if (i == 0)
	    {
	      len = list->real_size;
	      i++;
	      save = list;
	      printf("%p - ", (void *)list);
	      list = list->next;
	    }
	  else
	    {
	      printf("%p : %d octet\n",(void *)list, len);
	      i = 0;
	    }
	}
      else
	list = list->next;
    }
  if (i)
    printf("%p : %d octet\n", (void *)((unsigned int)save + len), len);
}

